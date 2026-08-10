#ifndef PIGEON_AUDIO_H
#define PIGEON_AUDIO_H

#include <libdragon.h>

typedef enum SFX {
  STEP
} SFX;

typedef struct {
  int currentTrackId;
  xm64player_t tranquilWalk;
  wav64_t step;
} PigeonAudio;

PigeonAudio *getPigeonAudio(void);

void pigeonAudioInit(void);
void playTrack(int trackId);
void stopTrack(int trackId);
void clearTrack(void);

void playSFX(SFX sfx);

// void updateAudio(void);

#endif