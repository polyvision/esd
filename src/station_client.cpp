#include "../inc/station_client.h"
#include "../inc/qlogger.h"
#include "../inc/app_settings.h"


int StationClient::m_iThreadCounter = 0;

StationClient::StationClient(QTcpSocket *connection){
	m_pNetworkManager = NULL;
	this->m_pClientConnection = connection;
	m_bExitThread = false;

	connect(this, SIGNAL(started()), this, SLOT(threadStarted()));
	connect(m_pClientConnection, SIGNAL(readyRead()), this, SLOT(readIncoming()));
	connect(m_pClientConnection, SIGNAL(disconnected()), this, SLOT(lostConnection()));
	connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
	this->inc_thread_counter();
}


StationClient::~StationClient(){
	disconnect(this, SIGNAL(started()), this, SLOT(threadStarted()));

	if(m_pNetworkManager){
		delete m_pNetworkManager;
	}
	
	
	QLogger::instance()->log(1,QString("StationClient deleted"));
	this->dec_thread_counter();
}

void StationClient::inc_thread_counter(){
	m_iThreadCounter++;
	QLogger::instance()->log(1,QString("StationClient:inc_thread_counter: %1").arg(m_iThreadCounter));
}

void StationClient::dec_thread_counter(){
	m_iThreadCounter--;
	QLogger::instance()->log(1,QString("StationClient:dec_thread_counter: %1").arg(m_iThreadCounter));
}

void StationClient::threadStarted(){
	// updating some thread stuff
	//while(!this->m_bExitThread){
	//	qApp->processEvents(QEventLoop::AllEvents,10);
	//}
	//QLogger::instance()->log(1,QString("StationClient:: exiting thread"));
}

void StationClient::readIncoming(){
	QDataStream in(m_pClientConnection);


	uint len = m_pClientConnection->bytesAvailable();
	char *incoming = new char[len];

	int bytesRead = in.readRawData(incoming,len);
	QLogger::instance()->log(1,QString("CO_MSP100::incoming msg bytes: %1, bytes read %2").arg(len).arg(bytesRead));
	for(int i = 0; i < len; i++)
	{
		m_strIncomingMessage.append(incoming[i]);
	}

	delete [] incoming;
	incoming = NULL;

	if(m_strIncomingMessage.contains("#") && (m_strIncomingMessage.contains("ON") || m_strIncomingMessage.contains("OFF")))
	{
		QLogger::instance()->log(1,QString("StationClient::incoming msg:\n%1").arg(m_strIncomingMessage));

		//QString sound_file = m_strIncomingMessage.replace("PLAY ","").replace("#","");
		//QLogger::instance()->log(1,QString("PsdServer:readIncomming: PLAY %1").arg(sound_file));
		//SoundEngine::instance()->enqueueSample(sound_file);

		if(m_strIncomingMessage.contains("ON")){
			
			this->emitos_api_request(m_strIncomingMessage.remove("ON").remove(" ").remove("#"),true);
		}else{
			this->emitos_api_request(m_strIncomingMessage.remove("OFF").remove(" ").remove("#"),false);
		}
		m_strIncomingMessage.clear(); // und dannn die nachricht wieder löschen
	}
	else{
		QLogger::instance()->log(1,QString("StationClient:readIncoming: inc message does not contain # -> %1").arg(m_strIncomingMessage));
	}
}

void StationClient::lostConnection(){
	QLogger::instance()->log(1,QString("StationClient:lostConnection"));
	this->m_bExitThread = true;
	m_pClientConnection->abort();
	this->m_pClientConnection->deleteLater();
	this->quit();
}

void StationClient::emitos_api_request(QString mac,bool activate){
	QLogger::instance()->log(1,QString("StationClient:emitos_api_request starting"));
	m_pNetworkManager = new QNetworkAccessManager(this);
 	connect(m_pNetworkManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(api_request_finished(QNetworkReply*)));

	QString url;
 	if(activate){

 		url = QString("%1/api/callbox/activate/%2").arg(AppSettings::get_emitos_host()).arg(mac);	
 	}else{
 		url = QString("%1/api/callbox/deactivate/%2").arg(AppSettings::get_emitos_host()).arg(mac);	
 	}
 	
	QLogger::instance()->log(1,QString("StationClient:emitos_api_request url: %1").arg(url));
 	m_pNetworkManager->get(QNetworkRequest(QUrl(url)));
}

void StationClient::api_request_finished(QNetworkReply * reply){
	QLogger::instance()->log(1,QString("StationClient:api_request_finished"));
	reply->deleteLater();
	this->m_bExitThread = true;
	this->quit();
}
