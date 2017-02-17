#ifndef AUDIO_SOURCE_COMPONENT_H
#define AUDIO_SOURCE_COMPONENT_H

#include "../Component.h"
#include "../AudioSystem.h"

class AudioSourceComponent : public Component {
public:
	AudioSourceComponent();
	~AudioSourceComponent();
	void LoadWAVFromFile(const char* filename);
	void Play();
private:
	ALuint source;
	int numBuffers;
	ALuint buffer;
	ALenum format;
	ALsizei freq;
};
#endif