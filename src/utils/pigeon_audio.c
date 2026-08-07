#include "pigeon_audio.h"
#include <libdragon.h>

const int FREQUENCY = 44100;
const int AUDIO_BUFFERS = 4;
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

void pigeonAudioInit(void) {
  audio_init(FREQUENCY, AUDIO_BUFFERS);
  mixer_init(MIXER_CHANNELS);

  PigeonAudio *pA = getPigeonAudio();
  xm64player_open(&pA->mainTrack, "rom:/bg.xm64");
}

void playTrack(int trackId) {
  PigeonAudio *pA = getPigeonAudio();
  if (!pA || trackId == pA->currentTrackId) {
    return;
  }

  switch(trackId) {
    case 0:
      xm64player_play(&pA->mainTrack, 0);
      xm64player_set_loop(&pA->mainTrack, true);
      xm64player_set_vol(&pA->mainTrack, 0.5f);
      break;
    default:
      assertf(false, "Audio track ID isn't handled: %d", trackId);

  }

  pA->currentTrackId = trackId;
}

void updateAudio(void) {
  if (audio_can_write()) {
		// Select an audio buffer that we can write to
		// short *buf = audio_write_begin();
		// // Write to the audio buffer from the mixer
		// mixer_poll(buf, audio_get_buffer_length());
		// // Tell the audio system that the buffer has
		// // been filled and is ready for playback
		// audio_write_end();
    mixer_try_play();
	}
}

void clearTrack(void) {
  // void xm64player_stop(xm64player_t *player);
  // void xm64player_close(xm64player_t *player);
}