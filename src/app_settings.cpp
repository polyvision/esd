#include "inc/app_settings.h"
#include "inc/sound_engine.h"
#include <stdio.h>

AppSettings::AppSettings(){
	
}

void AppSettings::setRecordingDevice(int v){
	QSettings settings;
	settings.setValue("esd_recording_device",v);
	printf("saved recording device to: ");
	SoundEngine::print_recording_device_info(v);
}

void AppSettings::setSoundDevice(int v){
	QSettings settings;
	settings.setValue("esd_sound_device",v);
	printf("saved sound device to: ");
	SoundEngine::print_device_info(v);	
}

int AppSettings::get_sound_device(){
	QSettings settings;
	return settings.value("esd_sound_device",0).toInt();
}

int AppSettings::get_recording_device(){
	QSettings settings;
	return settings.value("esd_recording_device",0).toInt();
}


void AppSettings::set_station_server_port(int v){
	QSettings settings;
	settings.setValue("station_server_port",v);
	printf("saved station server port to: %i\n",v);
}

int AppSettings::get_station_server_port(){
	QSettings settings;
	return settings.value("station_server_port",8866).toInt();	
}

void AppSettings::set_emitos_host(QString v){
	QSettings settings;
	settings.setValue("emitos_host",v);
	printf("saved emitos_host to: %s\n",v.toStdString().c_str());
}

QString AppSettings::get_emitos_host(){
	QSettings settings;
	return settings.value("emitos_host","http://localhost/").toString();	
}

void AppSettings::set_recording_bit_rate(int v){
	QSettings settings;
	settings.setValue("emitos_recording_bit_rate",v);
	printf("saved recording bit rate to: %i\n",v);
}

int AppSettings::get_recording_bit_rate(){
	QSettings settings;
	return settings.value("emitos_recording_bit_rate",48000).toInt();	
}

void AppSettings::set_playback_bit_rate(int v){
	QSettings settings;
	settings.setValue("emitos_playback_bit_rate",v);
	printf("saved playback bit rate to: %i\n",v);
}

int AppSettings::get_playback_bit_rate(){
	QSettings settings;
	return settings.value("emitos_playback_bit_rate",48000).toInt();	
}

void AppSettings::set_sound_volume(float v){
	QSettings settings;
	settings.setValue("emitos_sound_volume",v);
	printf("saved sound volume to: %f\n",v);
}

float AppSettings::get_sound_volume(){
	QSettings settings;
	return settings.value("emitos_sound_volume",1.0f).toFloat();	
}
	
void AppSettings::set_music_volume(float v){
	QSettings settings;
	settings.setValue("emitos_music_volume",v);
	printf("saved music volume to: %f\n",v);
}

float  AppSettings::get_music_volume(){
	QSettings settings;
	return settings.value("emitos_music_volume",1.0f).toFloat();	
}

void AppSettings::print_info(){
	QSettings settings;

	int recording_device = settings.value("esd_recording_device",0).toInt();
	int sound_device = settings.value("esd_sound_device",0).toInt();

	printf("using sound device: ");
	SoundEngine::print_device_info(sound_device);	

	printf("using recording device: ");
	SoundEngine::print_recording_device_info(recording_device);

	printf("recording sound bit rate: %ihz\n",AppSettings::get_recording_bit_rate());
	printf("playback sound bit rate: %ihz\n",AppSettings::get_playback_bit_rate());

	printf("station server port: %i\n",AppSettings::get_station_server_port());
	printf("emitos host: %s\n",AppSettings::get_emitos_host().toStdString().c_str());

	printf("music volume: %f\n",AppSettings::get_music_volume());
	printf("sound volume: %f\n",AppSettings::get_sound_volume());
}
