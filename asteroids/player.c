
//player.c

#include "renderer.h"
#include "player.h"

void init_player(struct player* p)
{
    struct vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    p->hit_radius = 15;
    p->lives = 3;
    p->location.x = 0;
    p->location.y = 0;
    p->velocity.x = 0;
    p->velocity.y = 0;
    p->obj_vert[0].x = 0;
    p->obj_vert[0].y = 1.5;
    p->obj_vert[1].x = -1;
    p->obj_vert[1].y = -1;
    p->obj_vert[2].x = 1;
    p->obj_vert[2].y = -1;

    //convert player verts from object space to world space
    for(uint8_t i = 0; i < P_VERTS; ++i) {

        multiply_vector(&p->obj_vert[i], -1);
        multiply_vector(&p->obj_vert[i], 12);
        add_vector(&p->world_vert[i], &p->obj_vert[i]);
        add_vector(&p->world_vert[i], &translation);
    }

    for(uint8_t i = 0; i < BULLETS; ++i) {

        p->bullets[i].alive = FALSE;
    }
}

void apply_force(struct vector2d* velocity, struct vector2d* thrust)
{
    add_vector(velocity, thrust);
}

void get_direction(struct vector2d* direction, struct player* p)
{
    direction->x = p->obj_vert[0].x;
    direction->y = p->obj_vert[0].y;

    normalise_vector(direction);
}

void shoot_bullet(struct player* p)
{
    for (uint8_t i = 0; i < BULLETS; ++i) {
    
        if (p->bullets[i].alive == FALSE) {
        
            p->bullets[i].alive = TRUE;
            p->bullets[i].location = p->world_vert[0];
            get_direction(p->bullets[i].velocity, p);
            multiply_vector(&p->bullets[i].velocity, 4.1);
            break;
        }
    }
}

void draw_player(window_t * win, struct player* p)
{
    draw_intensity(win, _G);    // Player in Green

    if (p->lives > 0) {

        draw_position(win, p->world_vert[0].x, p->world_vert[0].y);
        draw_line(win, p->world_vert[1].x, p->world_vert[1].y);
        draw_line(win, p->world_vert[2].x, p->world_vert[2].y);
        draw_line(win, p->world_vert[0].x, p->world_vert[0].y);
    }

    draw_intensity(win, _R);    // Bullets in Red

    //draw verts representing the bullets
    for (uint8_t i = 0; i < BULLETS; ++i) {

        if (p->bullets[i].alive == TRUE) {
        
            draw_pixel(win, p->bullets[i].location.x, p->bullets[i].location.y);
        }
    }
}

void update_player(struct player* p)
{
    struct vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    limit_vector(&p->velocity, 2);
    add_vector(&p->location, &p->velocity);

    for (uint8_t i = 0; i < P_VERTS; ++i) {

        p->world_vert[i].x = 0; p->world_vert[i].y = 0;
        add_vector(&p->world_vert[i], &p->obj_vert[i]);
        add_vector(&p->world_vert[i], &p->location);
        add_vector(&p->world_vert[i], &translation);
    }

    for (uint8_t i = 0; i < BULLETS; ++i) {

        add_vector(&p->bullets[i].location, &p->bullets[i].velocity);
    }
}

void rotate_player(struct player* p, FLOAT degrees) {

    for (uint8_t i =0; i < P_VERTS; ++i) {

        rotate_vector(&p->obj_vert[i], degrees);
    }
}

void bounds_player(struct player* p) {

    if (p->location.x < -SCREEN_WIDTH / 2) {
    
        p->location.x = SCREEN_WIDTH / 2;
    }

    if (p->location.x > SCREEN_WIDTH / 2) {
    
        p->location.x = -SCREEN_WIDTH / 2;
    }

    if (p->location.y < -SCREEN_HEIGHT / 2) {
    
        p->location.y = SCREEN_HEIGHT / 2;
    }

    if (p->location.y > SCREEN_HEIGHT / 2) {
    
        p->location.y = -SCREEN_HEIGHT / 2;
    }

    //bullet is out of bounds, reset bullet to be shot again
    //bullets are in world space
    for (uint8_t i = 0; i < BULLETS; ++i) {
    
        if (p->bullets[i].location.x < 0 || p->bullets[i].location.x >= SCREEN_WIDTH) {
        
            p->bullets[i].alive = FALSE;
        }
    
        if (p->bullets[i].location.y < 0 || p->bullets[i].location.y >= SCREEN_HEIGHT) {
        
            p->bullets[i].alive = FALSE;
        }
    }
}

