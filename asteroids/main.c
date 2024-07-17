/*
 * Demo name   : asteroids
 * Author      : Phillip Stevens @feilipu
 * Version     : V0.3
*/

//Using ReGIS and standard IO

#include "vector.h"
#include "renderer.h"
#include "player.h"
#include "asteroids.h"

#pragma printf = "%s %c %u %0d"     // enables %s, %c, %u, %d (formatted) only

#define ASTEROIDS 27
#define LIVES 3

window_t window;                        //The window we'll be rendering to
struct asteroid asteroids[ASTEROIDS];   //The asteroids
struct player p;                        //The player
struct player lives[LIVES];             //Player lives left

// Translation between the world and the screen with offset.
struct vector2d translation = {-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2};

int main(void)
{
    printf("Initialising... ");

    //Initialize ReGIS
    if (window_new(&window, SCREEN_WIDTH, SCREEN_HEIGHT, stdout) == 0)
    {
        printf("ReGIS could not initialize!\n");
        return 0;
    }
    // set window to Overlay Mode
    draw_mode(&window, _OVL);

    uint8_t offset = 0;

    //set up icons used to represent player lives
    for (uint8_t i = 0; i < LIVES; ++i) {

        init_player(&lives[i]);
        lives[i].lives = 1;

        //shrink lives
        for (uint8_t j = 0; j < P_VERTS; ++j) {

            divide_vector(&lives[i].obj_vert[j], 2);
        }

        //convert screen space vector into world space
        struct vector2d top_left;
        top_left.x = 20 + offset; top_left.y = 20;
        add_vector(&top_left, &translation);
        lives[i].location.x = top_left.x;
        lives[i].location.y = top_left.y;
        update_player(&lives[i]);
        offset += 20;
    }

    printf("Player & Asteroids.\n");

    //set up player and asteroids in world space
    init_player(&p);
    init_asteroids(asteroids, ASTEROIDS);

    uint32_t next_game_tick;
    uint32_t sleep = 0;

    // set up delay
    //uint32_t next_game_tick = millis();

    //render loop
    for(;;) {

        int keycode = getk();

        if (keycode == ASCII_ESC) {
            //Quit ReGIS Graphics
            window_close(&window);
            return 0;
        }

        if (keycode == 's' || keycode == 'S') {

            struct vector2d thrust;
            thrust.x = p.obj_vert[0].x;
            thrust.y = p.obj_vert[0].y;
            normalise_vector(&thrust);
            multiply_vector(&thrust, .06);
            apply_force(&p.velocity, &thrust);
        }

        if (keycode == 'a' || keycode == 'A') {

            rotate_player(&p, -4);
        }

        if (keycode == 'd' || keycode == 'D') {

            rotate_player(&p, 4);
        }

        if (keycode == ASCII_SPACE) {

             do {

                if (p.lives > 0) {
                    shoot_bullet(&p);
                } else break;

            } while (keycode = getk() == ASCII_SPACE);
        }

        //draw to the screen window
        clear_pixels(&window, _D);
        draw_player(&window, &p);
        draw_player(&window, &lives[0]);
        draw_player(&window, &lives[1]);
        draw_player(&window, &lives[2]);
        draw_asteroids(&window, asteroids, ASTEROIDS);

        update_player(&p);
        bounds_player(&p);
        bounds_asteroids(asteroids, ASTEROIDS);

        int res = collision_asteroids(asteroids, ASTEROIDS, &p.location, p.hit_radius);

        if (res != -1) {

            p.lives--;
            p.location.x = 0;
            p.location.y = 0;
            p.velocity.x = 0;
            p.velocity.y = 0;

            for ( uint8_t i = LIVES; i != 0; --i) {

                if(lives[i].lives > 0) {

                    lives[i].lives = 0;
                    break;
                }
            }
        }

        for (uint8_t i = 0; i < BULLETS; i++) {

            //only check for collision for bullets that are shown on screen
            if (p.bullets[i].alive == TRUE) {

                //convert bullet screen space location to world space to compare
                //with asteroids world space to detect a collision
                struct vector2d world = {0,0};
                add_vector(&world, &p.bullets[i].location);
                add_vector(&world, &translation);
                int index = collision_asteroids(asteroids, ASTEROIDS, &world, 1);

                //collision occured
                if (index != -1) {

                    asteroids[index].alive = 0;
                    p.bullets[i].alive = FALSE;

                    if (asteroids[index].size != SMALL) {

                        spawn_asteroids(asteroids, ASTEROIDS, asteroids[index].size, asteroids[index].location);
                    }
                }
            }
        }

        update_asteroids(asteroids, ASTEROIDS);


        next_game_tick += 1000 / 60;
//      sleep = next_game_tick - millis();

        if( sleep >= 0 ) {

//          delay(sleep);
        }
    }

    //Quit ReGIS Graphics
    window_close(&window);
 
    return 0;
}

