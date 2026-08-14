#ifndef PIGEON_UI_H
#define PIGEON_UI_H

#include "libdragon.h"

typedef struct {
  sprite_t *a_button;
} UI;

UI *getUI(void);

void ui_init_sprites(void);

#endif