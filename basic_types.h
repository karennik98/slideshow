#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

#include <stdint.h>

struct Position
{
    int32_t x;
    int32_t y;
    Position& operator =(const Position& pos) {
        x = pos.x;
        y = pos.y;
        return *this;
    }
};

struct Dimension
{
    int32_t width;
    int32_t height;
    Dimension& operator = (const Dimension& dim) {
        width = dim.width;
        height = dim.height;
        return *this;
    }
};

struct Point
{
    int32_t x;
    int32_t y;
    Point& operator =(const Point& pos) {
        x = pos.x;
        y = pos.y;
        return *this;
    }
};

#endif // BASIC_TYPES_H
