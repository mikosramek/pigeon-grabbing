/*
* PARKNORTH SCENE
* GENERATED ON 2026-08-26
*/
// INCLUDES
#include "parkNorth.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

// ENTITIES
#include "../entities/feather.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene ParkNorth = (Scene) {
  .id = 1,
  .name = "ParkNorth",
  .actorCount = 23,
  .modelCount = 7,
  .entityCount = 1,
  .doorCount = 3,
  .spawnCount = 3,
};

Scene *getBaseParkNorth() {
  return &ParkNorth;
}

// LOAD FUNCTION
Scene *createParkNorth(void) {
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // SPAWN POINT SETUP
  SpawnPoint *spawns = malloc_uncached(sizeof(SpawnPoint) * ParkNorth.spawnCount);
  spawns[0] = (SpawnPoint){
    .id = 3,
    .angle = 1.559999942779541,
    .spawn = (fm_vec3_t){{ 0.0f * xPositionMultiplier, -0, -0.0f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 4,
    .angle = 1.1030865907669067,
    .spawn = (fm_vec3_t){{ 25.967714309692383f * xPositionMultiplier, -0, 25.0361385345459f * zPositionMultiplier }},
  };
  spawns[2] = (SpawnPoint){
    .id = 5,
    .angle = 1.559999942779541,
    .spawn = (fm_vec3_t){{ -29.98514747619629f * xPositionMultiplier, -0, 9.024652481079102f * zPositionMultiplier }},
  };

  ParkNorth.spawns = spawns;

  // DOOR SETUP
  Door *doors = malloc_uncached(sizeof(Door) * ParkNorth.doorCount);
  doors[0] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (0.0f * xPositionMultiplier) - (5.0 * xPositionMultiplier), 0, (-4.013331890106201f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (0.0f * xPositionMultiplier) + (5.0 * xPositionMultiplier), 0, (-4.013331890106201f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
  };
  doors[1] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) - (5.0 * xPositionMultiplier), 0, (5.986668109893799f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) + (5.0 * xPositionMultiplier), 0, (5.986668109893799f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
  };
  doors[2] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (29.0f * xPositionMultiplier) - (1.0 * xPositionMultiplier), 0, (24.98666763305664f * zPositionMultiplier) - (5.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (29.0f * xPositionMultiplier) + (1.0 * xPositionMultiplier), 0, (24.98666763305664f * zPositionMultiplier) + (5.0 * zPositionMultiplier) }},
  };

  ParkNorth.doors = doors;


  // MODEL IMPORT
	ModelData fat_pigeon = setupModel("rom:/fat_pigeon.t3dm");
	ModelData park_north_ground = setupModel("rom:/park_north_ground.t3dm");
	ModelData park_north_walls = setupModel("rom:/park_north_walls.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * ParkNorth.modelCount);
	models[0] = fat_pigeon.model;
	models[1] = park_north_ground.model;
	models[2] = park_north_walls.model;
	models[3] = iron_trim.model;
	models[4] = rock_wall_long.model;
	models[5] = feather.model;
	models[6] = rock_post.model;


  ParkNorth.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * ParkNorth.actorCount);
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &park_north_walls,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &park_north_ground,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -9.338617324829102f * xPositionMultiplier, -1.0f * yPositionMultiplier, 22.109373092651367f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.998724102973938f, 0.0f, 0.0f, -0.05049978941679001f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 7.932077407836914f * xPositionMultiplier, -4.0f * yPositionMultiplier, 28.346012115478516f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.906396210193634f, 0.0f, 0.0f, 0.4224287271499634f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.741633415222168f * xPositionMultiplier, 0.0f * yPositionMultiplier, 32.18394470214844f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9997519254684448f, 0.0f, 0.0f, -0.022271305322647095f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 6.332939147949219f * xPositionMultiplier, -3.0f * yPositionMultiplier, 15.952690124511719f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.47090500593185425f, 0.0f, 0.0f, 0.8821837902069092f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.181934356689453f * xPositionMultiplier, -2.0f * yPositionMultiplier, 14.273594856262207f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9821704626083374f, 0.0f, 0.0f, 0.18799200654029846f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 0.8006281852722168f * xPositionMultiplier, -3.799537181854248f * yPositionMultiplier, 23.46477699279785f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.906396210193634f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 3.350133180618286f * scaleMultiplier, 3.350133180618286f * scaleMultiplier, 1.0089550018310547f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.929537773132324f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, -7.026008605957031f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071068286895752f, 0.0f, 0.0f, -0.7071067094802856f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.787884712219238f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, -7.1110005378723145f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071066498756409f, 0.0f, 0.0f, -0.70710688829422f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.082406997680664f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 9.310710906982422f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.1972246170043945f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 0.039127349853515625f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999243021011353f, 0.0f, 0.0f, -0.012306091375648975f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.533724784851074f * xPositionMultiplier, 1.924025058746338f * yPositionMultiplier, -7.026010513305664f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071068286895752f, 0.0f, 0.0f, -0.7071067094802856f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -4.392071723937988f * xPositionMultiplier, 1.924025058746338f * yPositionMultiplier, -7.111000061035156f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071068286895752f, 0.0f, 0.0f, -0.7071067094802856f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.101173400878906f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 11.832655906677246f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071066498756409f, 0.0f, 0.0f, -0.70710688829422f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.705360412597656f * xPositionMultiplier, 1.924025058746338f * yPositionMultiplier, 11.832655906677246f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071068286895752f, 0.0f, 0.0f, -0.7071067094802856f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.10116958618164f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 25.567739486694336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071066498756409f, 0.0f, 0.0f, -0.70710688829422f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.70535659790039f * xPositionMultiplier, 1.924025058746338f * yPositionMultiplier, 25.567739486694336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071068286895752f, 0.0f, 0.0f, -0.7071067094802856f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.082406997680664f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 30.90627098083496f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &fat_pigeon,
    /* POSITION     */ (float[3]){ -25.623680114746094f * xPositionMultiplier, 2.5946035385131836f * yPositionMultiplier, 24.20075798034668f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.20877142250537872f, 0.0f, 0.0f, -0.9779645204544067f },
    /* SCALE        */ (float[3]){ 0.6295814514160156f * scaleMultiplier, 0.7065135836601257f * scaleMultiplier, 0.5139351487159729f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -5.041791915893555f * xPositionMultiplier, -2.075974941253662f * yPositionMultiplier, 0.05805344507098198f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999243021011353f, 0.0f, 0.0f, -0.012306091375648975f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -25.619508743286133f * xPositionMultiplier, -3.142040729522705f * yPositionMultiplier, 24.23647689819336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier, 1.461161732673645f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ 0.8384191989898682f * xPositionMultiplier, 1.1246172189712524f * yPositionMultiplier, 23.471511840820312f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6920505166053772f, 0.0f, 0.0f, 0.7218490839004517f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  ParkNorth.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * ParkNorth.entityCount);
	entities[0] = createFeather(1, &actors[22]);

  ParkNorth.entities = entities;
  
  return &ParkNorth;  
}

// UNLOAD FUNCTION
void unloadParkNorth(void) {
  for (int i = 0; i < ParkNorth.modelCount; i++) {
    cleanupModel(ParkNorth.models[i]);
  }

  free_uncached(ParkNorth.models);

  for (int i = 0; i < ParkNorth.actorCount; i++) {
    deleteActor(&ParkNorth.actors[i]);
  }

  free_uncached(ParkNorth.actors);
  free_uncached(ParkNorth.entities);
  free_uncached(ParkNorth.spawns);
  free_uncached(ParkNorth.doors);
}
