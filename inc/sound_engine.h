#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include "inc/bass.h"

class SoundEngine{

public:
	SoundEngine();	

	static void	list_devices();
	static void print_device_info(int n);

	bool initialize();
private:
};
#endif