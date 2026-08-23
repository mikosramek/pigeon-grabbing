#include "feather.h"

#include "entity.h"
#include "../state.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_ui.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

// float getPlayerDist(struct Entity *feather) {
//   Player *player = getPlayer();
//   fm_vec3_t myPos = {{ feather->actor->staticPos[0], feather->actor->staticPos[1], feather->actor->staticPos[2] }};
//   float playerDist = fm_vec3_distance(&player->position, &myPos);
//   return playerDist;
// }

void updateFeather(struct Entity *feather, uint32_t time) {
  // float dist = getPlayerDist(feather);
  // if (feather->skip || dist > 75.0f) {
  //   return;
  // }

  float yOffset = sin(time * 0.05f) * 0.75f;
  feather->actor->pos[1] = feather->actor->staticPos[1] + yOffset;
}

bool canInteract(struct Entity *feather) {
  if (feather->skip) {
    return false;
  }
  // see if player is within AABB bounds
  Player *player = getPlayer();
  // aabb
  bool xAligned = player->position.x >= feather->interactionMin[0] && player->position.x <= feather->interactionMax[0];
  bool zAligned = player->position.z >= feather->interactionMin[2] && player->position.z <= feather->interactionMax[2];
  return xAligned && zAligned;
}

void interact(struct Entity *feather) {
  State *state = getState();
  feather->skip = true;
  deleteActor(feather->actor);
  // TODO: handling actual collection
  state->feathersCollected += 1;
}

void interactionUI(void) {
  UI *ui = getUI();
  // TODO: figure out this ui
  rdpq_sprite_blit(ui->a_button, 8, 230 - 12, &(rdpq_blitparms_t){
    .scale_x = 0.5f, .scale_y = 0.5f,
  });
  rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 26, 230, "collect feather");
}

struct Entity createFeather(Actor *actor) {
  int aabbScale = 10;
  struct Entity newFeather = (struct Entity) {
    .entityId = 0,
		.update = *updateFeather,
    .canInteract = *canInteract,
    .interact = *interact,
    .interactionUI = *interactionUI,
		.actor = actor,
    .skip = false,
    .interactionMin = {
      (int)(actor->staticPos[0] - aabbScale),
      (int)(actor->staticPos[1] - aabbScale),
      (int)(actor->staticPos[2] - aabbScale),
    },
    .interactionMax = {
      (int)(actor->staticPos[0] + aabbScale),
      (int)(actor->staticPos[1] + aabbScale),
      (int)(actor->staticPos[2] + aabbScale),
    }
	};
  return newFeather;
}