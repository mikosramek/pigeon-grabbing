
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


struct InventoryItem* getNextUnlockedItem(struct InventoryItem *current);
struct InventoryItem* getPreviousUnlockedItem(struct InventoryItem *current);

struct InventoryItem* init_inventory(bool inventory[]);

#endif