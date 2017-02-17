#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include <AL/al.h>
#include <AL/alc.h>

class AudioSystem {
public:
	AudioSystem();
	~AudioSystem();

	bool usable;
private:
	ALCdevice* audioDevice;
	ALCcontext* audioContext;
};

#endif

