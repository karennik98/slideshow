#ifndef OBJECT_H
#define OBJECT_H

#include "iobject.h"
#include "declaration.h"
#include "property.h"
#include "basic_types.h"

#include <QVector>

#include <memory>

class IShape;

class ObjectBase : public IObject
{
public:
//    ObjectBase(std::unique_ptr<PropertyBase> property)
//        : mProperty(std::move(property))
//    {}

    ObjectBase(PropertyBase* property)
        : mProperty(property)
    {}
    ID getID() const { return mProperty->getID(); }

    virtual void move(Position pos) override;
    virtual void resize(Dimension dim) override;
    virtual void rotate(double angle) override;

protected:
    std::unique_ptr<PropertyBase> mProperty;
};


class Object : public ObjectBase
{
public:
    //Object(std::unique_ptr<PropertyBase> property, std::unique_ptr<IShape> shape);
    Object(PropertyBase* property, IShape* shape);
private:
    std::unique_ptr<IShape> mShape;
};


class Group : public ObjectBase
{
public:
    bool addObject(IObject* object);
    bool removeObject(/*IObject* object*/ ID id); // TODO with iterator
private:
    QVector<IObject*> mObjects;
};

#endif // OBJECT_H
