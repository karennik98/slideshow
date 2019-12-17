#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QString>

class ICommand
{
public:
    ICommand(QString name)
        : mName(name)
    {}
    QString getName();
    virtual void execute() = 0;
protected:
    QString mName;
};

#endif // ICOMMAND_H
