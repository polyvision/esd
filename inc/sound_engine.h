#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include "inc/bass.h"
#include "inc/singleton.h"
#include <QString>
#include <QList>
#include <QThread>

class SoundEngine: public QThread,public Singleton<SoundEngine> {
	Q_OBJECT
	friend class Singleton<SoundEngine>;

public slots:
	void shutdown();

public:
	SoundEngine();	

	static void	list_devices();
	static void	list_recording_devices();
	static void print_device_info(int n);
	static void print_recording_device_info(int n);

	bool initialize();

	void playSample(QString);
	void enqueueSample(QString);

	void run();

	bool is_recording();
	bool start_recording();
	bool stop_recording();
	bool continue_recording();

private:
	QList<QString> m_lSamplesToPlay;
	bool	m_bExitThread;
	DWORD	m_dwCurrentActiveChannel;
	HRECORD m_dwCurrentRecordingChannel;
	HSTREAM m_dwCurrentRecordingOutputChannel;
};
#endif