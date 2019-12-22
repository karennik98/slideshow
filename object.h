#ifndef OBJECT_H
#define OBJECT_H

#include "iobject.h"
#include "declaration.h"
#include "property.h"
#include "basic_types.h"
#include "ishape.h"
#include "shapes.h"

#include <QVector>

#include <memory>

class IShape;

class ObjectBase : public IObject
{
public:
    ObjectBase(std::unique_ptr<PropertyBase> property)
        : IObject()
        , mProperty(std::move(property))
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
    Object(std::unique_ptr<PropertyBase> property, std::unique_ptr<IShape> shape);
private:
    std::unique_ptr<IShape> mShape;
};


class Group : public ObjectBase
{
public:
    bool addObject(IObject* object);
    bool removeObject(/*IObject* object*/ ID id); // TODO with iterator
private:
    QVector<std::unique_ptr<IObject>> mObjects;
};

#endif // OBJECT_H
