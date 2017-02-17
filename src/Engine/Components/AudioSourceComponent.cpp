#include <cstdio>
#include "AudioSourceComponent.h"

AudioSourceComponent::AudioSourceComponent() {
	numBuffers = 0;
	buffer = 0;
	alGenSources(1, &source);
}

AudioSourceComponent::~AudioSourceComponent() {
	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);
}

void AudioSourceComponent::LoadWAVFromFile(const char* filename) {
	FILE* wavFile = fopen(filename, "rb");

	/* Copy file into a temporary buffer */
  if (wavFile) {
	  fseek(wavFile, 0, SEEK_END);
		long fsize = ftell(wavFile);
		fseek(wavFile, 0, SEEK_SET);

		unsigned char* wav = new unsigned char[fsize];
		fread(wav, 1, fsize, wavFile);
    fsize -= fsize % 4;

		//TODO - Detect wav file type
		ALenum wavFileType;
		if (wav[0x16] == 0x01) {
			wavFileType = AL_FORMAT_MONO16;
		}
		else {
			wavFileType = AL_FORMAT_STEREO16;
		}
		freq = wav[0x19] << 8;
		freq += wav[0x18];
		alGenBuffers(1, &buffer);
		alBufferData(buffer, wavFileType, wav, fsize, freq);
		alSourcei(source, AL_BUFFER, buffer);



		delete[] wav;
		fclose(wavFile);
	}
}

void AudioSourceComponent::Play() {
	if (buffer) {
		alSourcePlay(source);
	}
}