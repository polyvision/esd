#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <QCoreApplication>
#include <QTextStream>

#include "inc/sound_engine.h"
#include "inc/app_settings.h"

void default_stuff(){
	// default stuff
	QCoreApplication::setOrganizationName("polyvisionUG");
    QCoreApplication::setOrganizationDomain("polyvision.org");
    QCoreApplication::setApplicationName("emitos_service_daemon");
}

int main(int argc,char **argv){


	if(argc >= 2){
		if(strcmp(argv[1],"list_sound_devices") == 0){
			default_stuff();
			SoundEngine::list_devices();
		}
		else if(strcmp(argv[1],"set_recording_device") == 0){
			default_stuff();
			AppSettings::setRecordingDevice(atoi(argv[2]));
		}
		else if(strcmp(argv[1],"daemon") == 0){
			QCoreApplication a(argc, argv);
			QTextStream qout(stdout);
			default_stuff();
			qout << "daemon started" << endl;
			return QCoreApplication::exec();
		}
	}else{
		printf("list_sound_devices - listing sound devices\n");
		printf("set_recording_device NUM - set recording devices\n");
		printf("daemon - runs the esd as a server daemon process\n");
	}
	return 0;
}