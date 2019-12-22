#include "object.h"
#include "iobject.h"

Object::Object(std::unique_ptr<PropertyBase> property, std::unique_ptr<IShape> shape)
    : ObjectBase(std::move(property))
    , mShape(std::move(shape))
{

}

//Object::Object(PropertyBase* property, IShape* shape)
//    : ObjectBase(property)
//    , mShape(shape)

//{}

void ObjectBase::move(Position pos)
{
    mProperty->setPosition(pos); // TODO think about +pos
}

void ObjectBase::resize(Dimension dim)
{
    mProperty->setDimension(dim); // TODO think about +dim
}

void ObjectBase::rotate(double angle)
{
    //TODO meybe id unused
}
