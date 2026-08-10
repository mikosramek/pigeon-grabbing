#ifndef PIGEON_AUDIO_H
#define PIGEON_AUDIO_H

#include <libdragon.h>

typedef struct {
  int currentTrackId;
  xm64player_t tranquilWalk;
} PigeonAudio;

PigeonAudio *getPigeonAudio(void);

void pigeonAudioInit(void);
void playTrack(int trackId);
void stopTrack(int trackId);
void clearTrack(void);

// void updateAudio(void);

#endif