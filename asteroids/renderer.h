
//renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if __8085
#include <_DEVELOPMENT/sccz80/lib/cpm/regis.h>
#elif __RC2014
#include <lib/rc2014/regis.h>
#elif __YAZ180
#include <lib/yaz180/regis.h>
#elif __CPM
#include <_DEVELOPMENT/sccz80/lib/cpm/regis.h>
#endif

//Screen dimension constants
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 480

void draw_pixel(window_t * win, uint16_t x, uint16_t y, w_intensity_t colour);

void draw_line(window_t * win, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, w_intensity_t colour);

//assign a colour to all pixels
void clear_pixels(window_t * win, w_intensity_t colour);

#endif //RENDERER_H

