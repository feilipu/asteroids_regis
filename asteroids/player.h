
//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif

#define P_VERTS 3
#define BULLETS 3

enum boolean {TRUE, FALSE};

struct bullet {

    struct vector2d location;
    struct vector2d velocity;
    enum boolean alive;
};

struct player {

    FLOAT hit_radius;
    uint8_t lives;
    struct vector2d location;
    struct vector2d velocity;
    struct vector2d obj_vert[P_VERTS];
    struct vector2d world_vert[P_VERTS];
    struct bullet bullets[BULLETS];
};

void init_player(struct player* p) __z88dk_fastcall;

void draw_player(window_t * win, struct player* p) __z88dk_callee;

void shoot_bullet(struct player* p) __z88dk_fastcall;

void update_player(struct player* p) __z88dk_fastcall;

void bounds_player(struct player* p) __z88dk_fastcall;

void apply_force(struct vector2d* velocity, struct vector2d* thrust) __z88dk_callee;

void rotate_player(struct player* p, FLOAT degrees) __z88dk_callee;

void get_direction(struct vector2d* direction, struct player* p) __z88dk_callee;

#ifdef __cplusplus
}
#endif

#endif //PLAYER_H

