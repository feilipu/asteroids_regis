
//renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ASCII_NULL      0x00        // null
#define ASCII_BELL      0x07        // bell
#define ASCII_BS        0x08        // backspace
#define ASCII_TAB       0x09        // horizontal tab
#define ASCII_LF        0x0A        // line feed
#define ASCII_VT        0x0B        // vertical tab
#define ASCII_FF        0x0C        // form feed (new page)
#define ASCII_CR        0x0D        // carriage return

#define ASCII_ESC       0x1B        // escape

#define ASCII_SPACE     0x20        // space
#define ASCII_HASH      0x23        // #
#define ASCII_LB        0x28        // (
#define ASCII_RB        0x29        // )
#define ASCII_COMMA     0x2C        // ,
#define ASCII_PERIOD    0x2E        // .
#define ASCII_SLASH     0x2f        // /

#define ASCII_SEMI      0x3B        // ;

#define ASCII_LSB       0x5B        // [
#define ASCII_BSLASH    0x5C        // back slash
#define ASCII_RSB       0x5D        // ]

#define WIDTH_MAX       768         // maximum width  (ReGIS maximum 768)
#define HEIGHT_MAX      480         // desired height (ReGIS maximum 480)

#define SCREEN_WIDTH    768         // Screen dimension constants
#define SCREEN_HEIGHT   480

/* offset direction */
typedef enum offset_e
{
    _EE  = 0,
    _NE  = 1,
    _NN  = 2,
    _NW  = 3,
    _WW  = 4,
    _SW  = 5,
    _SS  = 6,
    _SE  = 7
} offset_t;

/* writing mode */
typedef enum w_mode_e
{
    _REP = 0,           // (R) Replace Mode (standard mode)
    _ERA = 1,           // (E) Erase Mode - NOR
    _OVL = 2,           // (V) Overlay Mode - OR
    _CPL = 3            // (C) Complement Mode - XOR
} w_mode_t;

/* writing pattern */
typedef enum w_pattern_e
{
    _P0  = 0,           // blank
    _P1  = 1,           // solid
    _P2  = 2,           // dash
    _P3  = 3,           // dit dash
    _P4  = 4,           // dot
    _P5  = 5,           // dit dit dash
    _P6  = 6,
    _P7  = 7,
    _P8  = 8,
    _P9  = 9
} w_pattern_t;

/* intensity (colour) I(c) */
typedef enum w_intensity_e
{
    _D   = 0,           // Dark (black)
    _B   = 1,           // Blue
    _R   = 2,           // Red
    _M   = 3,           // Magenta
    _G   = 4,           // Green
    _C   = 5,           // Cyan
    _Y   = 6,           // Yellow
    _W   = 7            // White
} w_intensity_t;

/* Structure to use when opening a window - as per usual,if type <> 0
 * then open graphics window number with width (in pixels) width.
 */

typedef struct window_s {
    FILE * fp;          // display (output) device

    uint16_t width;     // desired window width  (ReGIS maximum 768)
    uint16_t height;    // desired window height (ReGIS maximum 480)
} window_t;

/****************************************************************************/
/***        Function Definitions                                          ***/
/****************************************************************************/

/* Open a graphics window in graphics mode */
uint8_t window_create(window_t * win, uint16_t width, uint16_t height, FILE * fp) __z88dk_callee;

/* Set writing mode */
void draw_mode(window_t * win, w_mode_t mode) __z88dk_callee;

/* Set writing colour */
void draw_intensity(window_t * win, w_intensity_t colour) __z88dk_callee;

/* Inititialise graphics window*/
void window_open(window_t * win) __z88dk_callee;

/* Clear window */
void window_clear(window_t * win) __z88dk_fastcall;

/* Close a graphics window, return to text mode */
void window_close(window_t * win) __z88dk_fastcall;

void draw_pixel(window_t * win, uint16_t x, uint16_t y) __z88dk_callee;

/* Position the drawing location */
void draw_position(window_t * win, uint16_t x, uint16_t y) __z88dk_callee;

/* Draw line from previous position to given position */
void draw_line(window_t * win, uint16_t x, uint16_t y) __z88dk_callee;

#ifdef __cplusplus
}
#endif

#endif //RENDERER_H

