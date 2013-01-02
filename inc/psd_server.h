#ifndef PSD_SERVER_H
#define PSD_SERVER_H

#include "inc/singleton.h"
#include <QtNetwork>

class PsdServer : public QObject,public Singleton<PsdServer>{
	Q_OBJECT

	friend class Singleton<PsdServer>;

public:
	bool 		initialize();

public slots:
	void			incomingConnection();
	void			readIncoming();
	void			lostConnection();

private:
	PsdServer();

	QTcpServer	*m_pTcpServer;
	QTcpSocket	*m_pTCPConnection;
	QString		m_strIncomingMessage;
	QMutex		m_mutex;
};
#endif