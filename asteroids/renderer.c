
//renderer.c

#include "renderer.h"

void draw_line(window_t * win, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, w_intensity_t colour)
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

    fprintf(win->fp, "V[%.3d,%.3d][%.3d,%.3d]", x1, y1, x2, y2);
}

void draw_pixel(window_t * win, uint16_t x, uint16_t y, w_intensity_t colour)
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

    fprintf(win->fp, "P[%.3d,%.3d]V[]", x, y);
}

void clear_pixels(window_t * win, w_intensity_t colour)
{
    fputs("S(E)", win->fp);

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

