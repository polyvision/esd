#include "inc/sound_engine.h"
#include <stdio.h>

SoundEngine::SoundEngine(){
	
}

void SoundEngine::list_devices(){
	printf("listing sound devices...\n");
	int a=0;
	BASS_DEVICEINFO info;
	for (a=0; BASS_GetDeviceInfo(a, &info); a++){
		SoundEngine::print_device_info(a);
	}
}

void SoundEngine::print_device_info(int n){
	BASS_DEVICEINFO info;
	BASS_GetDeviceInfo(n, &info);
	if (info.flags&BASS_DEVICE_ENABLED){ // device is enabled
		printf("device %i %s <%s>\n",n,info.name,info.driver);
	}  
}

bool SoundEngine::initialize(){
	
}