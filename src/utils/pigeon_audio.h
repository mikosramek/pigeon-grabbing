#ifndef PIGEON_AUDIO_H
#define PIGEON_AUDIO_H

#include <libdragon.h>

typedef enum SFX {
  STEP
} SFX;

typedef enum BackgroundMusic {
  TITLE,
  TRANQUIL_WALK
} BackgroundMusic;

typedef struct {
  int currentTrackId;
  xm64player_t title;
  xm64player_t tranquilWalk;
  xm64player_t *currentTrack;
  wav64_t step;
} PigeonAudio;

PigeonAudio *getPigeonAudio(void);

void p_audio_init(void);
void p_audio_play_track(BackgroundMusic trackToPlay);
void p_audio_stop_track(BackgroundMusic trackToPlay);
void p_audio_clear_track(void);

void p_audio_play_SFX(SFX sfx);

// void updateAudio(void);

#endif