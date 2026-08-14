#include "feather.h"

#include "entity.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_ui.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

void updateFeather(struct Entity *feather, uint32_t time) {
  if (feather->skip) {
    return;
  }

  float yOffset = sin(time / 10.0f) * 0.75f;
  feather->actor->pos[1] = feather->actor->staticPos[1] + yOffset;
}

bool canInteract(struct Entity *feather) {
  Player *player = getPlayer();
  if (feather->skip) {
    return false;
  }
  fm_vec3_t myPos = {{ feather->actor->pos[0], feather->actor->pos[1], feather->actor->pos[2] }};
  float playerDist = fm_vec3_distance(&player->position, &myPos);

  return playerDist < 20.0f;
}

void interact(struct Entity *feather) {
  feather->skip = true;
  deleteActor(feather->actor);
  // TODO: handling actual collection
}

void interactionUI(void) {
  UI *ui = getUI();
  // TODO: figure out this ui
  rdpq_sprite_blit(ui->a_button, 320/2, 240/2, NULL);
}

struct Entity createFeather(Actor *actor) {
  struct Entity newFeather = (struct Entity) {
		.update = *updateFeather,
    .canInteract = *canInteract,
    .interact = *interact,
    .interactionUI = *interactionUI,
		.actor = actor,
    .skip = false,
	};
  return newFeather;
}