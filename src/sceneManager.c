#include <libdragon.h>
#include "globals.h"
#include "state.h"
#include "sceneManager.h"
#include "scenes/park.h"
#include "scenes/hedges.h"
#include "scenes/pond.h"
#include "scenes/test.h"

struct SceneManagerImpl {
    SceneManager public_methods; // Must be the first element
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
            unloadHedges(); break;
          case 2:
            unloadPond(); break;
          case 3:
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
          state->activeScene = createHedges(1); break;
        case 2:
          state->activeScene = createPond(2); break;
        case 3:
          state->activeScene = createPark(3); break;
        default:
          assertf(false, "Invalid scene-id: %d", sceneId);
      }
    }
    
    state->requestSceneId = -1;
}

// Constructor mapping
SceneManager* Scene_Manager_Create(int initial_scene_id) {
    struct SceneManagerImpl* impl = malloc_uncached(sizeof(struct SceneManager));
    if (!impl) return NULL;

    // Assign internal state
    State *state = getState();
    state->requestSceneId = initial_scene_id;

    // Bind function pointers
    impl->public_methods.update = update_impl;
    impl->public_methods.loadScene = loadScene_impl;

    return (SceneManager*)impl;
}

void Scene_Manager_Destroy(SceneManager* self) {
    free_uncached(self); // Frees the entire CounterImpl structure
}