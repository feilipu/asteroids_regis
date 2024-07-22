
//vector.c

#include "vector.h"

void add_vector(struct vector2d* a, struct vector2d* b)
{
    a->x += b->x;
    a->y += b->y;
}

void multiply_vector(struct vector2d* v, FLOAT n)
{
    v->x *= n;
    v->y *= n;
}

void divide_vector(struct vector2d* v, FLOAT n)
{
    v->x /= n;
    v->y /= n;
}

void print_vector(struct vector2d* a)
{
    printf("\nx = %f\ny = %f\n", a->x, a->y);
}

void normalise_vector(struct vector2d* v)
{
    FLOAT n = INVSQRT(SQR(v->x) + SQR(v->y));
    v->x *= n;
    v->y *= n;
}

void limit_vector(struct vector2d* v, FLOAT limit)
{
    FLOAT mag = HYPOT(v->x, v->y);

    if (mag > limit) {

        FLOAT ratio = limit / mag;
        v->x *= ratio;
        v->y *= ratio;
    }
}

void rotate_vector(struct vector2d* v, FLOAT degrees)
{
    //calculate radians
    FLOAT angle = degrees * (M_PI / 180);
    FLOAT sine = SIN(angle);
    FLOAT cosine = COS(angle);

    //rotation matix
    FLOAT matrix[2][2];
    matrix[0][0] = cosine;
    matrix[0][1] = -sine;
    matrix[1][0] = sine;
    matrix[1][1] = cosine;

    FLOAT x = v->x;
    FLOAT y = v->y;

    v->x = matrix[0][0] * x + matrix[0][1] * y;
    v->y = matrix[1][0] * x + matrix[1][1] * y;
}

