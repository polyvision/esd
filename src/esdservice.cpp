#include "../inc/esdservice.h"

#include "../inc/sound_engine.h"
#include "../inc/app_settings.h"
#include "../inc/psd_server.h"
#include "../inc/station_server.h"
#include "../inc/qlogger.h"
#include "../inc/ecycler.h"

EsdService::EsdService(int argc, char **argv)
{
    this->mi_state = STATE_DAEMON;
//    setServiceDescription("ESD sound service");
//    setServiceFlags(QtServiceBase::CanBeSuspended);
}

EsdService::~EsdService()
{
}

void EsdService::start(){
    QLogger::instance()->openLogFile("esd.log");
    //default_stuff();

    ECycler *pCycler = new ECycler();

    StationServer::instance()->initialize();
    SoundEngine::instance()->initialize();
    PsdServer::instance()->initialize();

    SoundEngine::instance()->start(); // starting the thread for the sound server
    SoundEngine::instance()->start_recording();




    QLogger::instance()->log(1,"daemon started");
}

void EsdService::stop(){

}

void EsdService::pause(){

}

void EsdService::resume(){

}

void EsdService::processCommand(int code){

}
