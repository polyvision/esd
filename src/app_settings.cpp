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

void AppSettings::print_info(){
	QSettings settings;

	int recording_device = settings.value("esd_recording_device",0).toInt();
	int sound_device = settings.value("esd_sound_device",0).toInt();

	printf("using sound device: ");
	SoundEngine::print_device_info(sound_device);	

	printf("using recording device: ");
	SoundEngine::print_recording_device_info(recording_device);
}