#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <QSettings>

class AppSettings{

public:
	AppSettings();

	static void setSoundDevice(int v);
	static void setRecordingDevice(int v);

	static int get_sound_device();
	static int get_recording_device();
	
	static void set_station_server_port(int);
	static int 	get_station_server_port();

	static void set_recording_bit_rate(int);
	static int 	get_recording_bit_rate();

	static void set_playback_bit_rate(int);
	static int 	get_playback_bit_rate();

	static void set_emitos_host(QString);
	static QString get_emitos_host();
	
	static void	print_info();
};

#endif