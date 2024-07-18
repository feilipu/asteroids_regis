
//asteroids.h

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VERTS 10

enum sizes {SMALL, MEDIUM, LARGE};

struct asteroid {

    uint8_t alive;
    enum sizes size;
    FLOAT hit_radius;
    FLOAT rotation;
    struct vector2d location;
    struct vector2d velocity;
    struct vector2d obj_vert[VERTS];
    struct vector2d world_vert[VERTS];
};

void init_asteroids(struct asteroid asteroids[], uint8_t size) __z88dk_callee;

void update_asteroids(struct asteroid asteroids[], uint8_t size) __z88dk_callee;

void draw_asteroids(window_t * win, struct asteroid asteroids[], uint8_t size) __z88dk_callee;

int shrink_asteroid(struct asteroid* a, uint8_t size) __z88dk_callee;

void spawn_asteroids(struct asteroid a[], uint8_t length, uint8_t size, struct vector2d v) __z88dk_callee;

void bounds_asteroids(struct asteroid asteroids[], uint8_t size) __z88dk_callee;

int collision_asteroids(struct asteroid asteroids[], uint8_t size, struct vector2d* v, FLOAT radius) __z88dk_callee;

#ifdef __cplusplus
}
#endif

#endif //ASTEROIDS_H
