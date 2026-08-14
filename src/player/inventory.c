
#include "inventory.h"
#include <libdragon.h>

struct InventoryItem* inventory_get_next_unlocked_item(struct InventoryItem *current) {
  struct InventoryItem *next = current->nextItem;
  if (next->isOwned) {
    return next;
  }
  return inventory_get_next_unlocked_item(next);
}

struct InventoryItem* inventory_get_previous_unlocked_item(struct InventoryItem *current) {
  struct InventoryItem *previous = current->previousItem;
  if (previous->isOwned) {
    return previous;
  }
  return inventory_get_previous_unlocked_item(previous);
}

struct InventoryItem* inventory_init(bool inventory[]) {
  struct InventoryItem *empty = NULL;
  struct InventoryItem *sunflowerSeed = NULL;
  struct InventoryItem *safflowerSeed = NULL;

  empty = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));
  sunflowerSeed = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));
  safflowerSeed = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));

  empty->id = 0;
  empty->name = "";
  empty->isOwned = inventory[0];
  empty->sprite = NULL;
  empty->nextItem = sunflowerSeed;
  empty->previousItem = sunflowerSeed;

  sunflowerSeed->id = 1;
  sunflowerSeed->name = "Sunflower Seed";
  sunflowerSeed->isOwned = inventory[1];
  sunflowerSeed->sprite = sprite_load("rom:/sunflower.sprite");
  sunflowerSeed->nextItem = safflowerSeed;
  sunflowerSeed->previousItem = empty;

  safflowerSeed->id = 2;
  safflowerSeed->name = "Safflower Seed";
  safflowerSeed->isOwned = inventory[2];
  safflowerSeed->sprite = sprite_load("rom:/safflower.sprite");
  safflowerSeed->nextItem = empty;
  safflowerSeed->previousItem = sunflowerSeed;

  return empty;
}