#ifndef STATION_CLIENT_H
#define STATION_CLIENT_H

#include <QtNetwork>
#include <QThread>
#include <QNetworkAccessManager>

class StationClient: public QThread{
	Q_OBJECT

public:
	StationClient(QTcpSocket*);
	~StationClient();

public slots:
	void			readIncoming();
	void			lostConnection();
	void			threadStarted();
	void			api_request_finished(QNetworkReply * reply);

private:
	void			inc_thread_counter();
	void			dec_thread_counter();
	
	static int m_iThreadCounter;
	
	QTcpSocket *m_pClientConnection;
	bool		m_bExitThread;
	QString		m_strIncomingMessage;
	QNetworkAccessManager *m_pNetworkManager;

	void		emitos_api_request(QString,bool);
};
#endif