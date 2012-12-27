#include "inc/app_settings.h"
#include "inc/sound_engine.h"
#include <stdio.h>

AppSettings::AppSettings(){
	
}

void AppSettings::setRecordingDevice(int v){
	QSettings settings;
	settings.setValue("esd_recording_device",v);
	printf("saved recording device to: ");
	SoundEngine::print_device_info(v);
}