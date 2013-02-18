#include "inc/psd_server.h"
#include "inc/qlogger.h"
#include "inc/sound_engine.h"

PsdServer::PsdServer(){
	m_pTcpServer = NULL;
	m_pTCPConnection = NULL;
}

bool PsdServer::initialize(){
	m_pTcpServer = new QTcpServer(0);
	m_pTcpServer->listen(QHostAddress::Any,8823);

	connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(incomingConnection()));

	QLogger::instance()->log(QLogger::QL_INFO,"PsdServer: waiting for connection on port 8823");
	return true;
}

void PsdServer::incomingConnection()
{
	if(m_pTCPConnection)
	{
		delete m_pTCPConnection;
		m_pTCPConnection = NULL;
	}

	m_pTCPConnection = m_pTcpServer->nextPendingConnection();
	if(m_pTCPConnection != NULL)
	{
		QLogger::instance()->log(QLogger::QL_INFO,QString("Eine Verbindung zu einem PSD-Client an %1:%2 wurde aufgebaut").arg(m_pTCPConnection->peerAddress().toString()).arg(m_pTCPConnection->peerPort()));
		connect(m_pTCPConnection, SIGNAL(readyRead()), this, SLOT(readIncoming()));
		connect(m_pTCPConnection, SIGNAL(disconnected()), this, SLOT(lostConnection()));
	}
	else
	{
		// warning
	}
}

void PsdServer::readIncoming()
{
	//QMutexLocker locker(&m_mutex);
	if(m_pTCPConnection == NULL){
		QLogger::instance()->log(1,"PsdServer:readIncoming m_pTCPConnection is null");
		return;
	}
		

	QDataStream in(m_pTCPConnection);


	uint len = m_pTCPConnection->bytesAvailable();
	char *incoming = new char[len];

	int bytesRead = in.readRawData(incoming,len);
	QLogger::instance()->log(1,QString("CO_MSP100::incoming msg bytes: %1, bytes read %2").arg(len).arg(bytesRead));
	for(int i = 0; i < len; i++)
	{
		m_strIncomingMessage.append(incoming[i]);
	}

	delete [] incoming;
	incoming = NULL;

	if(m_strIncomingMessage.contains("#") && m_strIncomingMessage.contains("PLAY"))
	{
		QLogger::instance()->log(1,QString("CO_PSD::incoming msg:\n%1").arg(m_strIncomingMessage));

		/*
		// jetzt nachricht abfeuern
		MObject *pMessageObject = new MObject(m_strIncomingMessage,this);
		MessageRouter::instance()->routeMessage(pMessageObject);*/

		//interpretePSDMessage(m_strIncomingMessage);
		QString sound_file = m_strIncomingMessage.replace("PLAY ","").replace("#","");
		QLogger::instance()->log(1,QString("PsdServer:readIncomming: PLAY %1").arg(sound_file));
		SoundEngine::instance()->enqueueSample(sound_file);

		m_strIncomingMessage.clear(); // und dannn die nachricht wieder löschen
	}
	else{
		QLogger::instance()->log(1,QString("PsdServer:readIncoming: inc message does not contain # -> %1").arg(m_strIncomingMessage));
	}
	m_pTCPConnection->close(); // close connection
	m_pTCPConnection->deleteLater();
	m_pTCPConnection = NULL;
}

/*
* wird aufgerufen wenn eine bestehende Verbindung unterbrochen / bzw beendet wird
*/
void PsdServer::lostConnection()
{
	QMutexLocker locker(&m_mutex);

	if(m_pTCPConnection != NULL)
	{
		QLogger::instance()->log(1,QString("PSD client disconnected"));
		QLogger::instance()->log(1,QString("PSD bytes to read %1").arg(m_pTCPConnection->bytesAvailable()));
		QLogger::instance()->log(1,QString("PSD bytes to write %1").arg(m_pTCPConnection->bytesToWrite()));
		
		m_pTCPConnection->disconnectFromHost();
		//m_pTCPConnection->waitForDisconnected();
		m_pTCPConnection->abort();
		m_pTCPConnection->deleteLater();
	}
}