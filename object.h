#ifndef OBJECT_H
#define OBJECT_H

#include "iobject.h"
#include "declaration.h"
#include "property.h"
#include "basic_types.h"

#include <QVector>

class IShape;

class ObjectBase : public IObject
{
public:
    ID getID() const { return mProperty->id; }
protected:
    PropertyBase* mProperty;
};

class Object : public ObjectBase
{
public:
    Object();
private:
    IShape* mShape;
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
