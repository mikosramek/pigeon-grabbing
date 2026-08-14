#include "pigeon_ui.h"

#include "libdragon.h"

static UI ui = {};

UI *getUI(void)
{
    return &ui;
}


void ui_init_sprites(void) {
  ui.a_button = sprite_load("rom:/ui_a.sprite");
}