#include "pigeon_audio.h"
#include <libdragon.h>

const int FREQUENCY = 48000;
const float AUDIO_BUFFERS = 4;
const int MIXER_CHANNELS = 32; // power of 2

#define CHANNEL_SFX1    0
#define CHANNEL_SFX2    1
#define CHANNEL_MUSIC   2

static PigeonAudio pigeonAudio = {
  .currentTrackId = -1
};

PigeonAudio *getPigeonAudio(void)
{
  return &pigeonAudio;
}


// use sm64 for background music
// use wav64 for sfx
void p_audio_init(void) {
  audio_init(FREQUENCY, AUDIO_BUFFERS);
  mixer_init(MIXER_CHANNELS);

  wav64_init_compression(3);

  PigeonAudio *pA = getPigeonAudio();
  xm64player_open(&pA->tranquilWalk, "rom:/tranquil_walk_no_melody.xm64");
  xm64player_set_loop(&pA->tranquilWalk, true);
  xm64player_set_vol(&pA->tranquilWalk, 0.5f);
  
  xm64player_open(&pA->title, "rom:/title.xm64");
  xm64player_set_loop(&pA->title, true);
  xm64player_set_vol(&pA->title, 0.5f);
  
  pA->currentTrack = NULL;

  wav64_open(&pA->step, "rom:/laser.wav64");
  wav64_set_loop(&pA->step, false);
}

// TODO: probably refactor this to take in a xm64player_t that each scene holds + loads, rather than have them all defined here at once
// only track the current / next track, so they can be transitioned to/from
void p_audio_play_track(BackgroundMusic trackToPlay) {
  PigeonAudio *pA = getPigeonAudio();

  if (pA->currentTrack && pA->currentTrack->playing) {
    xm64player_stop(pA->currentTrack);
  }

  switch(trackToPlay) {
    case TITLE:
      if (!pA->title.playing) {
        xm64player_play(&pA->title, CHANNEL_MUSIC);
        pA->currentTrack = &pA->title;
      }
      break;
    case TRANQUIL_WALK:
      if (!pA->tranquilWalk.playing) {
        xm64player_play(&pA->tranquilWalk, CHANNEL_MUSIC);
        pA->currentTrack = &pA->tranquilWalk;
      }
      break;
    default:
      assertf(false, "Audio track isn't handled in p_audio_play_track (%i)", (int)trackToPlay);
  }
}

void p_audio_play_SFX(SFX sfx) {
  PigeonAudio *pA = getPigeonAudio();

  switch (sfx) {
    case STEP:
      wav64_play(&pA->step, CHANNEL_SFX1);
      break;
    default:
      assertf(false, "SFX to play isn't handled in p_audio_play_SFX (%i)", (int)sfx);
      break;
  }
}

// this might be unnecessary, and currentTrack can just be stopped when changing to a new track
void p_audio_stop_track(BackgroundMusic trackToStop) {
  PigeonAudio *pA = getPigeonAudio();
  switch(trackToStop) {
    case TITLE:
      xm64player_stop(&pA->title);
      break;
    case TRANQUIL_WALK:
      xm64player_stop(&pA->tranquilWalk);
      break;
    default:
      assertf(false, "Audio track isn't handled in p_audio_stop_track (%i)", (int)trackToStop);
  }
  pA->currentTrack = NULL;
}

// void updateAudio(void) {
//   mixer_try_play();
// }

// TODO: figure out some sort of crossfade / transition between tracks

// TODO: unload tracks when needed (probably get called in unload scene functions)
void p_audio_clear_track(void) {
  // void xm64player_stop(xm64player_t *player);
  // void xm64player_close(xm64player_t *player);
}