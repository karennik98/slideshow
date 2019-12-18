#ifndef PROPERTY_H
#define PROPERTY_H

#include "basic_types.h"
#include "declaration.h"

struct PropertyBase
{
    PropertyBase(Position pos, Dimension dim, ID id)
        : mPos(pos)
        , mDim(dim)
        , mId(id)
    {}
    Position mPos;
    Dimension mDim;
    ID mId;
};

struct ShapeProperty : public PropertyBase
{
    ShapeProperty(Position pos, Dimension dim, ID id)
        : PropertyBase(pos, dim, id)
    {}
};

struct TextProperty : public PropertyBase
{
    bool bold;
    bool italic;
};

#endif // PROPERTY_H
