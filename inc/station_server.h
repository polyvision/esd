#ifndef STATION_SERVER_H
#define STATION_SERVER_H

#include "../inc/singleton.h"
#include <QtNetwork>

class StationServer: public QObject,public Singleton<StationServer>{
	Q_OBJECT

	friend class Singleton<StationServer>;
	
	public:
		bool initialize();

	public slots:
	void			incomingConnection();

	private:
		StationServer();

		QTcpServer	*m_pTcpServer;
};
#endif
