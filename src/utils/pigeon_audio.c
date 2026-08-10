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
void pigeonAudioInit(void) {
  audio_init(FREQUENCY, AUDIO_BUFFERS);
  mixer_init(MIXER_CHANNELS);

  wav64_init_compression(3);

  PigeonAudio *pA = getPigeonAudio();
  xm64player_open(&pA->tranquilWalk, "rom:/tranquil_walk_no_melody.xm64");
  xm64player_set_loop(&pA->tranquilWalk, true);
  xm64player_set_vol(&pA->tranquilWalk, 0.5f);

  wav64_open(&pA->step, "rom:/laser.wav64");
  wav64_set_loop(&pA->step, false);
}

// TODO: probably refactor this to take in a xm64player_t that each scene holds + loads, rather than have them all defined here at once
// only track the current / next track, so they can be transitioned to/from
void playTrack(BackgroundMusic trackToPlay) {
  PigeonAudio *pA = getPigeonAudio();

  switch(trackToPlay) {
    case TRANQUIL_WALK:
      if (!pA->tranquilWalk.playing) {
        xm64player_play(&pA->tranquilWalk, CHANNEL_MUSIC);
      }
      break;
    default:
      assertf(false, "Audio track isn't handled in playTrack (%i)", (int)trackToPlay);
  }
}

void playSFX(SFX sfx) {
  PigeonAudio *pA = getPigeonAudio();

  switch (sfx) {
    case STEP:
      wav64_play(&pA->step, CHANNEL_SFX1);
      break;
    default:
      assertf(false, "SFX to play isn't handled in playSFX (%i)", (int)sfx);
      break;
  }
}

void stopTrack(BackgroundMusic trackToStop) {
  PigeonAudio *pA = getPigeonAudio();
  switch(trackToStop) {
    case TRANQUIL_WALK:
      xm64player_stop(&pA->tranquilWalk);
      break;
    default:
      assertf(false, "Audio track isn't handled in stopTrack (%i)", (int)trackToStop);
  }
}

// void updateAudio(void) {
//   mixer_try_play();
// }

// TODO: figure out some sort of crossfade / transition between tracks

// TODO: unload tracks when needed (probably get called in unload scene functions)
void clearTrack(void) {
  // void xm64player_stop(xm64player_t *player);
  // void xm64player_close(xm64player_t *player);
}