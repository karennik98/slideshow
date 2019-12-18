#ifndef IOBJECT_H
#define IOBJECT_H

#include <basic_types.h>

class IObject
{
public:
    IObject();
    virtual void move(Position pos) = 0;
    virtual void resize(Dimension dim) = 0;
    virtual void rotate(double angle) = 0;
};

#endif // IOBJECT_H
