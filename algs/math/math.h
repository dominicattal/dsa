#ifndef MATH_H
#define MATH_H

typedef struct {
    int x, y;
} Point;

int intersect(Point A, Point B, Point C, Point D);

#endif