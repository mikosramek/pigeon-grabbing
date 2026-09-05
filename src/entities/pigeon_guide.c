#include "pigeon_guide.h"

#include "entity.h"
#include "../state.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_ui.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

// animation or movement
void pigeon_guide_update(struct Entity *pigeonGuide, uint32_t time) {
  // 
}

// determine if the object can be interacted with
bool pigeon_guide_can_interact(struct Entity *pigeonGuide) {
  if (pigeonGuide->skip) {
    return false;
  }
  // see if player is within AABB bounds
  Player *player = getPlayer();
  // aabb
  bool xAligned = player->position.x >= pigeonGuide->interactionMin[0] && player->position.x <= pigeonGuide->interactionMax[0];
  bool zAligned = player->position.z >= pigeonGuide->interactionMin[2] && player->position.z <= pigeonGuide->interactionMax[2];
  return xAligned && zAligned;
}

void pigeon_guide_interact(struct Entity *pigeonGuide) {
  // this can be handled based on ID (like, if ID is 0, and you interact, open up a gate (change entity state for gates[1] or something))
  if (pigeonGuide->id == 0) {
    // push dialogue
  } else if (pigeonGuide->id == 1) {
    // push different dialogue
  }
  // State *state = getState();
  pigeonGuide->skip = true;
  pigeonGuide->actor->skip = true;
  // state_update_feather(pigeonGuide->id, INACTIVE);
  // TODO: handling actual collection
  // state->feathersCollected += 1;
}

void pigeon_guide_interaction_ui(void) {
  UI *ui = getUI();
  // TODO: figure out this ui
  rdpq_sprite_blit(ui->a_button, 8, 230 - 12, &(rdpq_blitparms_t){
    .scale_x = 0.5f, .scale_y = 0.5f,
  });
  rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 26, 230, "talk");
}

struct Entity pigeon_guide_create(uint32_t entityId, Actor *actor) {
  // can do something like
  // if id = 0 & state is active, handle differently than id = 1 & is active
  // enum EntityState state = state_get_feather(entityId);
  int aabbScale = 10;
  struct Entity newPigeonGuide = (struct Entity) {
    .id = entityId,
		.update = *pigeon_guide_update,
    .canInteract = *pigeon_guide_can_interact,
    .interact = *pigeon_guide_interact,
    .interactionUI = *pigeon_guide_interaction_ui,
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

  // if (state == INACTIVE) {
  //   newFeather.skip = true;
  //   newFeather.actor->skip = true;
  // }

  return newPigeonGuide;
}