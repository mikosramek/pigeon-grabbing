
#ifndef INVENTORY_H
#define INVENTORY_H

#include <libdragon.h>

struct InventoryItem{
  uint32_t id;
  char *name;
  sprite_t *sprite;
  bool isOwned;
  struct InventoryItem *nextItem;
  struct InventoryItem *previousItem;
};


struct InventoryItem* inventory_get_next_unlocked_item(struct InventoryItem *current);
struct InventoryItem* inventory_get_previous_unlocked_item(struct InventoryItem *current);

struct InventoryItem* inventory_init(bool inventory[]);

#endif