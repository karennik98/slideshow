#ifndef SLIDE_H
#define SLIDE_H

#include <QVector>

#include <memory>

class IObject;

class Slide
{
public:
    Slide() = default;
    void addObject(std::unique_ptr<IObject> object);
private:
    QVector<std::unique_ptr<IObject>> mObjects;
};

#endif // SLIDE_H
