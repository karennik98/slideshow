#ifndef SHAPES_H
#define SHAPES_H

#include "ishape.h"

class Rect : public IShape
{
public:
    Rect(QString name)
      : IShape(name)
    {}
private:
    //TODO need some specific options
};

class Circle : public IShape
{
public:
    Circle(QString name)
      : IShape(name)
    {}
private:
    //TODO need some specific options
};

class Triangle : public IShape
{
public:
    Triangle(QString name)
      : IShape(name)
    {}
private:
    //TODO need some specific options
};

#endif // SHAPES_H
