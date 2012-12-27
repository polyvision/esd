#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <QSettings>

class AppSettings{

public:
	AppSettings();

	static void setRecordingDevice(int v);
};

#endif