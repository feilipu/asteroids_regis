
//renderer.c

#include "renderer.h"

/* Open a graphics window in graphics mode */
uint8_t window_create(window_t * win, uint16_t width, uint16_t height, FILE * fp)
{
    if(win != NULL)
    {
        if (fp != NULL) win->fp = fp; else return 0;
        if (width && width < WIDTH_MAX) win->width = width; else win->width = WIDTH_MAX-1;
        if (height && height < HEIGHT_MAX) win->height = height; else win->height = HEIGHT_MAX-1;
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Set writing mode */
void draw_mode(window_t * win, w_mode_t mode)
{
    switch (mode)
    {
        case _REP: fputs("W(R)", win->fp); break;
        case _ERA: fputs("W(E)", win->fp); break;
        case _OVL: fputs("W(V)", win->fp); break;
        case _CPL: fputs("W(C)", win->fp); break;
        default: break;
    }
}

/* Set writing colour */
void draw_intensity(window_t * win, w_intensity_t colour)
{
    switch (colour)
    {
        case _D: fputs("W(I(D))", win->fp); break;
        case _B: fputs("W(I(B))", win->fp); break;
        case _R: fputs("W(I(R))", win->fp); break;
        case _M: fputs("W(I(M))", win->fp); break;
        case _G: fputs("W(I(G))", win->fp); break;
        case _C: fputs("W(I(C))", win->fp); break;
        case _Y: fputs("W(I(Y))", win->fp); break;
        case _W: fputs("W(I(W))", win->fp); break;
        default: break;
    }
}

/* Inititialise graphics window */
void window_open(window_t * win)
{
    fprintf(win->fp, "%cP2p", ASCII_ESC);
}

/* Clear window */
void window_clear(window_t * win)
{
    fputs("S(E)", win->fp);
}

/* Close a graphics window, return to text mode */
void window_close(window_t * win)
{
    fprintf(win->fp, "%c%c\n", ASCII_ESC, ASCII_BSLASH);
}

void draw_pixel(window_t * win, uint16_t x, uint16_t y)
{
    fprintf(win->fp, "P[%.3d,%.3d]V[]", x, y);
}

/* Position the drawing location */
void draw_position(window_t * win, uint16_t x, uint16_t y)
{
    fprintf(win->fp, "P[%.3d,%.3d]", x, y);
}

/* Draw line from previous position to given position */
void draw_line(window_t * win, uint16_t x, uint16_t y)
{
    fprintf(win->fp, "V[%.3d,%.3d]", x, y);
}

