
//vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MATH_MATH16
#define FLOAT _Float16
#define SQR(x) sqrf16(x)
#define SQRT(x) sqrtf16(x)
#define INVSQRT(x) invsqrtf16(x)
#define COS(x) cosf16(x)
#define SIN(x) sinf16(x)

#elif __MATH_MATH32
#define FLOAT float
#define SQR(x) sqr(x)
#define SQRT(x) sqrt(x)
#define INVSQRT(x) invsqrt(x)
#define COS(x) cos(x)
#define SIN(x) sin(x)

#else
#define FLOAT float
#define SQR(x) sqr(x)
#define SQRT(x) sqrt(x)
#define INVSQRT(x) (1.0/sqrt(x))
#define COS(x) cos(x)
#define SIN(x) sin(x)
#endif

struct vector2d {

    FLOAT x;
    FLOAT y;
};

void add_vector(struct vector2d* a, struct vector2d* b) __z88dk_callee;

void multiply_vector(struct vector2d* v, FLOAT n) __z88dk_callee;

void divide_vector(struct vector2d* v, FLOAT n) __z88dk_callee;

void print_vector(struct vector2d* a) __z88dk_fastcall;

void normalise_vector(struct vector2d* v) __z88dk_fastcall;

void limit_vector(struct vector2d* v, FLOAT limit) __z88dk_callee;

void rotate_vector(struct vector2d* v, FLOAT degrees) __z88dk_callee;

#ifdef __cplusplus
}
#endif

#endif //VECTOR_H
