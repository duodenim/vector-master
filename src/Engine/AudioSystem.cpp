#include "AudioSystem.h"
#include <cstdlib>

AudioSystem::AudioSystem() {
	/* Initialilize audio device/context */
	audioDevice = alcOpenDevice(NULL);
	usable = false;
	if (audioDevice) {
		audioContext = alcCreateContext(audioDevice, NULL);
		if (audioContext) {
			alcMakeContextCurrent(audioContext);
			usable = true;
		}
	}

}

AudioSystem::~AudioSystem() {

	/* Shutdown system */
	if (audioContext) {
		alcDestroyContext(audioContext);
	}
	if (audioDevice) {
		alcCloseDevice(audioDevice);
	}

}