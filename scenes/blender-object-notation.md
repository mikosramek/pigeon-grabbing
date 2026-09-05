# Blender Plugin Export Notations

## Base Tags

| base tag | denotes                                             |
| -------- | --------------------------------------------------- |
| `a_`     | an actor                                            |
| `e_`     | an entity                                           |
| `d_`     | a door                                              |
| `sp_`    | a spawn point                                       |
| `floor_` | a floor plane to raycast against                    |
| `aabb_`  | an axis-aligned bounding box, for non-rotated walls |
| `obb_`   | an oriented bounding box, for rotated walls         |

## Modifier Flags

| modifier | denotes                             |
| -------- | ----------------------------------- |
| \*`sc_`  | mark as an object to skip culling   |
| `s_`     | skip (mark as hidden to start with) |

`*` currently not being used

## Entities

ids are scoped to that entity type (eg Feathers)

### Feather

### Pigeon Guide

## Floors

These are expected to use the `game_engine` gltf file - meaning their origin point is at the bottom of the cube
