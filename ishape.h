#ifndef ISHAPE_H
#define ISHAPE_H

#include <QString>

class IShape
{
public:
    IShape(QString name)
      : mName(name)
    {}

    QString getName() { return mName; }
    virtual ~IShape() {}
protected:
    QString mName;
};

#endif // ISHAPE_H
