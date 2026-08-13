
#include "inventory.h"
#include <libdragon.h>

struct InventoryItem* getNextUnlockedItem(struct InventoryItem *current) {
  struct InventoryItem *next = current->nextItem;
  if (next->isOwned) {
    return next;
  }
  return getNextUnlockedItem(next);
}

struct InventoryItem* getPreviousUnlockedItem(struct InventoryItem *current) {
  struct InventoryItem *previous = current->previousItem;
  if (previous->isOwned) {
    return previous;
  }
  return getPreviousUnlockedItem(previous);
}

struct InventoryItem* init_inventory(void) {
  struct InventoryItem *empty = NULL;
  struct InventoryItem *sunflowerSeed = NULL;
  struct InventoryItem *safflowerSeed = NULL;

  empty = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));
  sunflowerSeed = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));
  safflowerSeed = (struct InventoryItem *)malloc_uncached(sizeof(struct InventoryItem));

  empty->id = 0;
  empty->name = "";
  empty->isOwned = true;
  empty->sprite = sprite_load("rom:/ui_a.sprite");
  empty->nextItem = sunflowerSeed;
  empty->previousItem = sunflowerSeed;

  sunflowerSeed->id = 1;
  sunflowerSeed->name = "Sunflower Seed";
  sunflowerSeed->isOwned = true;
  sunflowerSeed->sprite = sprite_load("rom:/ui_b.sprite");
  sunflowerSeed->nextItem = safflowerSeed;
  sunflowerSeed->previousItem = empty;

  safflowerSeed->id = 2;
  safflowerSeed->name = "Safflower Seed";
  safflowerSeed->isOwned = true;
  safflowerSeed->sprite = sprite_load("rom:/ui_arrow.sprite");
  safflowerSeed->nextItem = empty;
  safflowerSeed->previousItem = sunflowerSeed;

  return empty;
}