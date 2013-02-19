#ifndef ECYCLER_H
#define ECYCLER_H

#include <QTimer>
#include <QNetworkAccessManager>
#include <QtNetwork>

class ECycler: public QObject{
	Q_OBJECT

public:
	ECycler();

public slots:
	void update();
	void api_request_finished(QNetworkReply * reply);
	
private:
	void emitos_api_request();
	
	QNetworkAccessManager *m_pNetworkManager;
};
#endif