#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QString>

#include <any>

class ICommand
{
public:
    ICommand(QString name)
        : mName(name)
    {}
    QString getName();
    virtual void execute(std::any args) = 0;
protected:
    QString mName;
};

#endif // ICOMMAND_H
