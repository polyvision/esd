#include "../inc/station_server.h"
#include "../inc/qlogger.h"
#include "../inc/app_settings.h"
#include "../inc/station_client.h"

StationServer::StationServer(): QObject(){
	m_pTcpServer = NULL;
}

bool StationServer::initialize(){
	m_pTcpServer = new QTcpServer(0);
	m_pTcpServer->listen(QHostAddress::Any,AppSettings::get_station_server_port());

	connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(incomingConnection()));

	QLogger::instance()->log(QLogger::QL_INFO,QString("StationServer: waiting for connection on port %1").arg(AppSettings::get_station_server_port()));
	return true;
}

void StationServer::incomingConnection()
{
	QTcpSocket	*pTcpConnection = m_pTcpServer->nextPendingConnection();
	if(pTcpConnection != NULL)
	{
		QLogger::instance()->log(QLogger::QL_INFO,QString("StationServer:: neue Verbindung an %1:%2 wurde aufgebaut").arg(pTcpConnection->peerAddress().toString()).arg(pTcpConnection->peerPort()));

		StationClient *pClient = new StationClient(pTcpConnection);
		pClient->start();
		//pTcpConnection->abort();
		//delete pTcpConnection;
		//connect(m_pTCPConnection, SIGNAL(readyRead()), this, SLOT(readIncoming()));
		//connect(m_pTCPConnection, SIGNAL(disconnected()), this, SLOT(lostConnection()));
	}
}
