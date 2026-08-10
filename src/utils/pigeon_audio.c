#include "pigeon_audio.h"
#include <libdragon.h>

const int FREQUENCY = 44100;
const float AUDIO_BUFFERS = 4;
const int MIXER_CHANNELS = 32; // power of 2

  // void audio_init (const int frequency, int numbuffers);
  // void mixer_init (int num_channels);
  // audio_init(44100, 20);
  // mixer_init(32);
  // mixer_ch_set_limits(6, 0, 128000, 0);
  // xm64player_t xm;
  // xm64player_open(&xm, "rom:/bg.xm64");
  // xm64player_play(&xm, 0);
  // xm64player_set_loop(&xm, true);

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

  PigeonAudio *pA = getPigeonAudio();
  xm64player_open(&pA->tranquilWalk, "rom:/tranquil_walk_no_melody.xm64");
  xm64player_set_loop(&pA->tranquilWalk, true);
  xm64player_set_vol(&pA->tranquilWalk, 0.5f);
}

void playTrack(int trackId) {
  PigeonAudio *pA = getPigeonAudio();

  switch(trackId) {
    case 0:
      if (!pA->tranquilWalk.playing) {
        xm64player_play(&pA->tranquilWalk, 0);
      }
      break;
    default:
      assertf(false, "Audio track ID isn't handled in playTrack: %d", trackId);
  }
}

void stopTrack(int trackId) {
  PigeonAudio *pA = getPigeonAudio();
  switch(trackId) {
    case 0:
      xm64player_stop(&pA->tranquilWalk);
      break;
    default:
      assertf(false, "Audio track ID isn't handled in stopTrack: %d", trackId);
  }
}

// void updateAudio(void) {
//   mixer_try_play();
// }

void clearTrack(void) {
  // void xm64player_stop(xm64player_t *player);
  // void xm64player_close(xm64player_t *player);
}