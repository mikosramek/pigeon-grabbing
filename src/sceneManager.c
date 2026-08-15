#include <libdragon.h>
#include "state.h"
#include "sceneManager.h"
#include "scenes/park.h"
#include "scenes/test.h"

const int SCENE_COUNT = 2;

struct SceneManagerImpl {
  SceneManager public_struct; // Must be the first element
  // include private keys here
};

static void loadScene_impl(int sceneId) {
    State *state = getState();
    state->requestSceneId = sceneId;
}

static void update_impl() {
    State *state = getState();
    int sceneId = state->requestSceneId;
    if(sceneId >= 0) {
      State *state = getState();
      rspq_wait();

      // unload current scene
      if (state->activeScene) {
        switch(state->activeScene->id) {
          case 0:
            unloadTest(); break;
          case 1:
            unloadPark(); break;
          default:
            assertf(false, "Current scene doesn't have an unload: %d", (int)state->activeScene->id);
        }
      }

      // create new scene
      switch(sceneId) {
        case 0:
          state->activeScene = createTest(0); break;
        case 1:
          state->activeScene = createPark(1); break;
        default:
          assertf(false, "Invalid scene-id: %d", sceneId);
      }
    }
    
    state->requestSceneId = -1;
}

// Constructor mapping
SceneManager* scene_manager_create(int initial_scene_id) {
    struct SceneManagerImpl* impl = malloc_uncached(sizeof(struct SceneManager));
    if (!impl) return NULL;

    // Assign internal state
    State *state = getState();
    state->requestSceneId = initial_scene_id;

    // Bind function pointers
    impl->public_struct.sceneCount = SCENE_COUNT;
    impl->public_struct.update = update_impl;
    impl->public_struct.loadScene = loadScene_impl;

    return (SceneManager*)impl;
}

void scene_manager_destroy(SceneManager* self) {
    free_uncached(self); // Frees the entire SceneManagerImpl structure
}