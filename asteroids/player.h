
//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "vector.h"

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

void init_player(struct player* p);

void draw_player(window_t * win, struct player* p);

void shoot_bullet(struct player* p);

void update_player(struct player* p);

void bounds_player(struct player* p);

void apply_force(struct vector2d* velocity, struct vector2d* thrust);

void rotate_player(struct player* p, FLOAT degrees);

void get_direction(struct vector2d* direction, struct player* p);

#endif //PLAYER_H

