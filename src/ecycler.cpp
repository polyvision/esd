#include "inc/ecycler.h"
#include "inc/qlogger.h"
#include "inc/app_settings.h"

ECycler::ECycler(){
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(3000);
}

void ECycler::update(){
	this->emitos_api_request();
}

void ECycler::emitos_api_request(){
	m_pNetworkManager = new QNetworkAccessManager(this);
 	connect(m_pNetworkManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(api_request_finished(QNetworkReply*)));

	QString	url = QString("%1/api/cycle").arg(AppSettings::get_emitos_host());	

 	
	//QLogger::instance()->log(1,QString("ECycler:emitos_api_request url: %1").arg(url));
 	m_pNetworkManager->get(QNetworkRequest(QUrl(url)));
}

void ECycler::api_request_finished(QNetworkReply * reply){
//	reply->deleteLater();
	delete reply;
}