#include "inc/sound_engine.h"
#include "inc/app_settings.h"
#include "inc/qlogger.h"
#include <stdio.h>
#include <cstdio>
#include <QCoreApplication>

SoundEngine::SoundEngine(){
	m_bExitThread = false;
	m_dwCurrentActiveChannel = 0;
	m_dwCurrentRecordingChannel = 0;
	m_dwCurrentRecordingOutputChannel = 0;
	m_bIsRecording = false;
	connect(qApp,SIGNAL(aboutToQuit()), this, SLOT(shutdown()));
}

void SoundEngine::list_devices(){
	printf("listing sound devices...\n");
	int a=0;
	BASS_DEVICEINFO info;
	for (a=0; BASS_GetDeviceInfo(a, &info); a++){
		SoundEngine::print_device_info(a);
	}
}

void SoundEngine::list_recording_devices(){
	printf("listing recording sound devices...\n");
	int a=0;
	BASS_DEVICEINFO info;
	for (a=0; BASS_RecordGetDeviceInfo(a, &info); a++){
		SoundEngine::print_recording_device_info(a);
	}
}

void SoundEngine::print_device_info(int n){
	BASS_DEVICEINFO info;
	BASS_GetDeviceInfo(n, &info);
	if (info.flags&BASS_DEVICE_ENABLED){ // device is enabled
		printf("device %i %s <%s>\n",n,info.name,info.driver);
	}  
}

void SoundEngine::print_recording_device_info(int n){
	BASS_DEVICEINFO info;
	BASS_RecordGetDeviceInfo(n, &info);
	if (info.flags&BASS_DEVICE_ENABLED){ // device is enabled
		printf("device %i %s <%s>\n",n,info.name,info.driver);
	}  
}

bool SoundEngine::initialize(){
	if (HIWORD(BASS_GetVersion())!=BASSVERSION) {
		QLogger::instance()->log(1,"SoundEngine: an incorrect version of BASS was loaded");
		return false;
	}

	// initialize default output device
	int sound_device = AppSettings::get_sound_device();
	if (!BASS_Init(sound_device,44100,0,NULL,NULL)) {
		QLogger::instance()->log(1,"SoundEngine: can't initialize playback device");
		return false;
	}

	QLogger::instance()->log(1,QString("SoundEngine: playback device %1 successfully initialized").arg(sound_device));

	// recording
	int recording_device = AppSettings::get_recording_device();
	
	if (!BASS_RecordInit(recording_device)) {
		QLogger::instance()->log(1,"SoundEngine: can't initialize recording device");
		return false;
	}

	QLogger::instance()->log(1,QString("SoundEngine: recording device %1 successfully initialized:").arg(recording_device));
	return true;
}

void SoundEngine::enqueueSample(QString v){
	m_lSamplesToPlay << v;
	QLogger::instance()->log(1,QString("SoundEngine::enqueueSample %1").arg(v));
}

void SoundEngine::playSample(QString samplePath){
	QLogger::instance()->log(1,QString("SoundEngine::playSample:<%1>").arg(samplePath));

	this->stop_recording();
	int error = 0;

	HSTREAM stream=BASS_StreamCreateFile(FALSE, samplePath.toStdString().c_str(), 0, 0, 0);
	if(stream == 0){
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::playSample: BASS_StreamCreateFile error %1").arg(error));
		}
	}else{
		QLogger::instance()->log(1,QString("SoundEngine::playSample: stream nr %1").arg(stream));
	}

	if(!BASS_ChannelPlay(stream,true)){
		QLogger::instance()->log(1,"SoundEngine: failed to play sample");
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::playSample: BASS_ChannelPlay error %1").arg(error));
		}
	}
	m_dwCurrentActiveChannel = stream; // current active channel setzen
}

void SoundEngine::run(){
	QLogger::instance()->log(1,"SoundEngine started thread");
	while(m_bExitThread == false){
		qApp->processEvents(QEventLoop::AllEvents,10);

		if(m_dwCurrentActiveChannel > 0){ // überprüfung ob ein sample am abspielen ist
			if(BASS_ChannelIsActive(m_dwCurrentActiveChannel) != BASS_ACTIVE_PLAYING &&
				BASS_ChannelIsActive(m_dwCurrentActiveChannel) != BASS_ACTIVE_STALLED){
				// nichts spielt ab, also auf zum nächsten sample falls eines das ist zum spielen
				if(m_lSamplesToPlay.isEmpty() == false){
					this->playSample(m_lSamplesToPlay.last());
					m_lSamplesToPlay.removeLast(); // das letzte rauslöschen
					QLogger::instance()->log(1,QString("SoundEngine: %1 samples left enqueued").arg(m_lSamplesToPlay.size()));
				}else{
					m_dwCurrentActiveChannel = 0;
				}
			}
		}else if(m_lSamplesToPlay.isEmpty() == false){
			this->playSample(m_lSamplesToPlay.last());
			m_lSamplesToPlay.removeLast(); // das letzte rauslöschen
			QLogger::instance()->log(1,QString("SoundEngine: %1 samples left enqueued").arg(m_lSamplesToPlay.size()));
		}else{
			if(this->is_recording() == false){
				this->continue_recording();
			}
		}
	}
	QLogger::instance()->log(1,"SoundEngine ended thread");
}

/**
 * checks if we are recording
 **/
bool SoundEngine::is_recording(){
	if(m_dwCurrentRecordingChannel <= 0){
		return false;
	}
	/*
 	if(BASS_ChannelIsActive(m_dwCurrentRecordingChannel) == BASS_ACTIVE_PAUSED){
 		return false;
 	}*/
	return m_bIsRecording;
}


BOOL CALLBACK RecordingCallback(HRECORD handle, const void *buffer, DWORD length, void *user){
	HSTREAM *output =  reinterpret_cast<HSTREAM*>(user);
 	BASS_StreamPutData(*output, buffer, length); // feed the recorded data to the output stream
 	return true;
}

bool SoundEngine::start_recording(){
	int error = 0;

	// the output stream for the recording	
	if(m_dwCurrentRecordingOutputChannel == 0){
		m_dwCurrentRecordingOutputChannel = BASS_StreamCreate(44100, 2, 0, STREAMPROC_PUSH, NULL);
	}

	if(!BASS_ChannelPlay(m_dwCurrentRecordingOutputChannel,true)){
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::start_recording: BASS_ChannelPlay error %1").arg(error));
		}
		return false;	
	}

	// the recording stuff itself
	
	if(m_dwCurrentRecordingChannel == 0){
		m_dwCurrentRecordingChannel = BASS_RecordStart(44100, 2, 0, &RecordingCallback, &m_dwCurrentRecordingOutputChannel);
		if(m_dwCurrentRecordingChannel <= 0){
			error = BASS_ErrorGetCode();
			if( error!= BASS_OK){
				QLogger::instance()->log(1,QString("SoundEngine::start_recording: BASS_RecordStart error %1").arg(error));
			}
			return false;
		}
		QLogger::instance()->log(1,QString("SoundEngine::start_recording: recording channel %1").arg(m_dwCurrentRecordingChannel));
	}


	m_bIsRecording = true;
	QLogger::instance()->log(1,"SoundEngine::start_recording: successfully started recording");
	return true;
}

/**
 * continues the recording process
 **/
bool SoundEngine::continue_recording(){
	int error = 0;
	
	if(m_dwCurrentRecordingChannel <= 0){
		return false;
	}

	/*if(!BASS_ChannelPlay(m_dwCurrentRecordingChannel,true)){
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::continue_recording: BASS_ChannelPlay error %1").arg(error));
		}
		return false;	
	}*/

	if(!BASS_ChannelSetAttribute(m_dwCurrentRecordingOutputChannel,BASS_ATTRIB_VOL,0.9f)){
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::continue_recording: BASS_ChannelSetAttribute error %1").arg(error));
			return false;
		}
	}
	QLogger::instance()->log(1,QString("SoundEngine::continue_recording successfull"));
	m_bIsRecording = true;
	return true;
}

/**
 * pauses / stops the recording process
 */
bool SoundEngine::stop_recording(){
	/*int error = 0;
	if(BASS_ChannelIsActive(m_dwCurrentRecordingChannel) == BASS_ACTIVE_STOPPED	){
		QLogger::instance()->log(1,QString("SoundEngine::stop_recording: recording channel seems not to be activate"));
		return true;
	}
	

	if(!BASS_ChannelPause(m_dwCurrentRecordingChannel)){
		error = BASS_ErrorGetCode();
		if( error!= BASS_OK){
			QLogger::instance()->log(1,QString("SoundEngine::stop_recording: BASS_ChannelStop error %1").arg(error));
		}
		return false;	
	}*/

	BASS_ChannelSetAttribute(m_dwCurrentRecordingOutputChannel,BASS_ATTRIB_VOL,0.0f);
	m_bIsRecording = false;
	QLogger::instance()->log(1,QString("SoundEngine::stop_recording: stopped recording"));
	return true;
}

void SoundEngine::shutdown(){
	QLogger::instance()->log(1,QString("SoundEngine::shutdown: started"));
	this->stop_recording();
	BASS_Free();
	QLogger::instance()->log(1,QString("SoundEngine::shutdown: shutdown finished"));
}