#include "object.h"
#include "iobject.h"

Object::Object(std::unique_ptr<PropertyBase> property, std::unique_ptr<IShape> shape)
    : ObjectBase(std::move(property))
    , mShape(std::move(shape))
{
}
