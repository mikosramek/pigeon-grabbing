// #include "libdragon.h"
// #include "state.h"

// struct entityState_entry* create_entity_state(uint32_t id, bool state) {
//   struct entityState_entry *newState = NULL;
//   newState = (struct entityState_entry *)malloc_uncached(sizeof(struct entityState_entry));

//   newState->id = id;
//   newState->state = state ? ACTIVE : INACTIVE;
//   newState->nextEntry = NULL;

//   return newState;
// }

// struct entityState_entry* entity_state_init(bool states[]) {
//   struct entityState_entry *feather1 = create_entity_state(-1, states[0]);
//   struct entityState_entry *feather2 = create_entity_state(0, states[1]);
//   struct entityState_entry *feather3 = create_entity_state(1, states[2]);


//   feather1->nextEntry = feather2;
//   feather2->nextEntry = feather3;
//   feather3->nextEntry = feather1;

//   return feather1;
// }

// struct entityState_entry* find_state(uint32_t id) {
//   State *s = getState();
//   struct entityState_entry *e = s->entityState;
//   if (e->id == id) {
//     return e;
//   }
//   return NULL;
//   // while (e->id != id && e->nextEntry != NULL) {
//   //   e = e->nextEntry;
//   // }
//   // assertf(e != NULL, "Trying to find state for an entity id that doesn't exist (%d)", (int)id);
//   // return e;
// }

// void update_entity_state(uint32_t id, enum EntityState state) {
//   struct entityState_entry *e = find_state(id);
//   e->state = state;
// }