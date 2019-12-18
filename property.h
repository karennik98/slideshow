#ifndef PROPERTY_H
#define PROPERTY_H

#include "basic_types.h"
#include "declaration.h"

struct PropertyBase
{
    ID id;
    Position pos;
    Dimension dim;
};

struct ShapeProperty : public PropertyBase
{

};

struct TextProperty : public PropertyBase
{
    bool bold;
    bool italic;
};

#endif // PROPERTY_H
