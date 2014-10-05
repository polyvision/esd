#include "../inc/qlogger.h"
#include <QMutexLocker>

/*
 * Info = Default LogLevel
 */
QLogger::QLogger() : QObject()
{
	m_pFile = NULL;
	m_pOutputStream = NULL;
	m_uiLogLevel = QLogger::QL_INFO;
	m_pStdOutputStream = new QTextStream(stdout);
}

QLogger::~QLogger()
{
	m_pFile->close();
}

void QLogger::setLogLevel(unsigned int v)
{
	m_uiLogLevel = v;
}

void QLogger::log(unsigned int level,QString v)
{
	m_mutex.lock();

	if(m_uiLogLevel >= level)
	{
		if(m_pOutputStream != NULL)
		{
			*m_pOutputStream << v << endl;
			*m_pStdOutputStream << v << endl;
		}
	}
	m_mutex.unlock();
}

bool QLogger::openLogFile(QString path)
{
	m_pFile = new QFile(path);
	if(m_pFile->open(QFile::WriteOnly) == false)
	{
		delete m_pFile;
		m_pFile = NULL;
		return false;
	}

	m_pOutputStream = new QTextStream(m_pFile);
	return true;
}
