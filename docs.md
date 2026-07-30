## an array of actors

```
INIT
rspq_block_t *dpls[2];
T3DModel *models[2] = {
  t3d_model_load("rom:/box.t3dm"),
  t3d_model_load("rom:/food.t3dm")
};

for(int i=0; i<2; ++i) {
  rspq_block_begin();
  t3d_model_draw(models[i]);
  dpls[i] = rspq_block_end();
}

Actor actors[ACTOR_COUNT];
for(int i=0; i<ACTOR_COUNT; ++i) {
  actors[i] = actor_create(i, dpls[i*3 % 2]);
}

LOOP
for(int i=0; i<actorCount; ++i) {
  actor_update(&actors[i]);
  // t3d_mat4fp_from_srt_euler(&actor->modelMat[frameIdx], actor->scale, actor->rot, actor->pos);
}

t3d_matrix_push_pos(1);
for(int i=0; i<actorCount; ++i) {
  actor_draw(&actors[i]);
  // t3d_matrix_set(&actor->modelMat[frameIdx], true);
  // rspq_block_run(actor->dpl);
}
t3d_matrix_pop(1);
```
