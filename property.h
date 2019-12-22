#ifndef PROPERTY_H
#define PROPERTY_H

#include "basic_types.h"
#include "declaration.h"

class PropertyBase
{
public:
    PropertyBase(Position pos, Dimension dim, ID id)
        : mPos(pos)
        , mDim(dim)
        , mId(id)
    {}
    virtual ~PropertyBase() {}
public:
    void setPosition(Position pos)   { mPos = pos; }
    void setDimension(Dimension dim) { mDim = dim; }
    void setId(ID id)                { mId = id;   }

    Position getPosition() const   { return mPos; }
    Dimension getDimension() const { return mDim; }
    ID getID() const               { return mId;  }
private:
    Position mPos;
    Dimension mDim;
    ID mId;
};

class ShapeProperty : public PropertyBase
{
public:
    ShapeProperty(Position pos, Dimension dim, ID id)
        : PropertyBase(pos, dim, id)
    {}
};

class TextProperty : public PropertyBase
{
public:
    bool bold;
    bool italic;
};

#endif // PROPERTY_H
