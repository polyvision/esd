#define NOMINMAX

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <unistd.h>
#include <limits>
#include <QCoreApplication>
#include <QTextStream>

#include "../inc/esdservice.h"

void default_stuff(){
	// default stuff
	QCoreApplication::setOrganizationName("polyvisionUG");
    QCoreApplication::setOrganizationDomain("polyvision.org");
    QCoreApplication::setApplicationName("emitos_service_daemon");
}

int main(int argc,char **argv){
    default_stuff();

    EsdService service(argc, argv);
    //return service.exec();

    /*
	if(argc >= 2){
		if(strcmp(argv[1],"list_sound_devices") == 0){
			default_stuff();
			SoundEngine::list_devices();
		}
		if(strcmp(argv[1],"list_recording_devices") == 0){
			default_stuff();
			SoundEngine::list_recording_devices();
		}
		else if(strcmp(argv[1],"set_recording_device") == 0){
			default_stuff();
			AppSettings::setRecordingDevice(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"set_sound_device") == 0){
			default_stuff();
			AppSettings::setSoundDevice(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"show_settings") == 0){
			default_stuff();
			AppSettings::print_info();
		}
		else if(strcmp(argv[1],"set_station_server_port") == 0){
			default_stuff();
			AppSettings::set_station_server_port(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"set_emitos_host") == 0){
			default_stuff();
			AppSettings::set_emitos_host(argv[2]);
		}
		else if(strcmp(argv[1],"set_recording_bit_rate") == 0){
			default_stuff();
			AppSettings::set_recording_bit_rate(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"set_playback_bit_rate") == 0){
			default_stuff();
			AppSettings::set_playback_bit_rate(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"set_sound_volume") == 0){
			default_stuff();
			AppSettings::set_sound_volume(atof(argv[2]));
		}
		else if(strcmp(argv[1],"set_music_volume") == 0){
			default_stuff();
			AppSettings::set_music_volume(atof(argv[2]));
		}
		else if(strcmp(argv[1],"fake_start") == 0){
			printf("fake start started");
			default_stuff();
			QCoreApplication a(argc, argv);
			SoundEngine::instance()->initialize();
			SoundEngine::instance()->start(); // starting the thread for the sound server
			SoundEngine::instance()->start_recording();
            //sleep(5);
			printf("fake start done");
		}
		else if(strcmp(argv[1],"daemon") == 0){
			QCoreApplication a(argc, argv);
			
			QLogger::instance()->openLogFile("esd.log");
			default_stuff();

			ECycler *pCycler = new ECycler();
			
			StationServer::instance()->initialize();
			SoundEngine::instance()->initialize();
			PsdServer::instance()->initialize();

			SoundEngine::instance()->start(); // starting the thread for the sound server
			SoundEngine::instance()->start_recording();
			

			

			QLogger::instance()->log(1,"daemon started");
			return QCoreApplication::exec();
		}
	}else{
		printf("EMITOS sound daemon v1.1.1 - (c) 2013-2014 by polyvision UG\n");
		printf("fake_start - fake start, initializes sound devices one time\n");
		printf("list_sound_devices - listing sound devices\n");
		printf("list_recording_devices - listing recording sound devices\n");
		printf("set_recording_device NUM - set recording devices\n");
		printf("set_station_server_port NUM - set TC/IP port for incomming call box connections\n");
		printf("set_sound_device NUM - set sound devices\n");
		printf("set_emitos_host HOST - set emitos host, e.g http://IP-ADDRESS/\n");
		printf("show_settings - lists all saved settings\n");
		printf("set_recording_bit_rate - set sound recording bit rate, e.g. 8000\n");
		printf("set_playback_bit_rate - set sound playback bit rate, e.g. 8000\n");
		printf("set_sound_volume - set sound volume, e.g. 0.5\n");
		printf("set_music_volume - set music volume, e.g. 0.5\n");
		printf("daemon - runs the esd as a server daemon process\n");
	}
	return 0;
    */
}
