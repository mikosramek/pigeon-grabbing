#ifndef PIGEON_AUDIO_H
#define PIGEON_AUDIO_H

#include <libdragon.h>

typedef enum SFX {
  STEP
} SFX;

typedef enum BackgroundMusic {
  TRANQUIL_WALK
} BackgroundMusic;

typedef struct {
  int currentTrackId;
  xm64player_t tranquilWalk;
  wav64_t step;
} PigeonAudio;

PigeonAudio *getPigeonAudio(void);

void pigeonAudioInit(void);
void playTrack(BackgroundMusic trackToPlay);
void stopTrack(BackgroundMusic trackToPlay);
void clearTrack(void);

void playSFX(SFX sfx);

// void updateAudio(void);

#endif