
//asteroids.h

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "vector.h"

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

void init_asteroids(struct asteroid asteroids[], uint8_t size);

void update_asteroids(struct asteroid asteroids[], uint8_t size);

void draw_asteroids(window_t * win, struct asteroid asteroids[], uint8_t size);

int shrink_asteroid(struct asteroid* a, uint8_t size);

void spawn_asteroids(struct asteroid a[], uint8_t length, uint8_t size, struct vector2d v);

void bounds_asteroids(struct asteroid asteroids[], uint8_t size);

int collision_asteroids(struct asteroid asteroids[], uint8_t size, struct vector2d* v, FLOAT radius);

#endif //ASTEROIDS_H
