#ifndef QLOGGER_H
#define QLOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include "../inc/singleton.h"

class QLogger : public QObject, public Singleton<QLogger>
{
	friend class Singleton<QLogger>;
	Q_OBJECT

public:
	static const unsigned int	QL_INFO		= 1; 
	static const unsigned int	QL_DEBUG	= 2;
	static const unsigned int	QL_FATAL	= 0;

	void	setLogLevel(unsigned int);
	bool	openLogFile(QString path);
	void	log(unsigned int level,QString);
private:
	QLogger();
	~QLogger();
	
	unsigned int	m_uiLogLevel;
	QFile			*m_pFile;
	QTextStream		*m_pOutputStream;
	QTextStream 	*m_pStdOutputStream;
	QMutex			m_mutex;
};
#endif
