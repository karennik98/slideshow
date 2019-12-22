#ifndef ICOMMAND_H
#define ICOMMAND_H
#include "action_controller.h"

#include <QString>

#include <any>
#include <memory>

class ICommand
{
public:
    ICommand(QString name)
        : mName(name)
        , mActionController(std::move(new ActionController))
    {}
    QString getName();
    virtual void execute(std::any args) = 0;
protected:
    QString mName;
    std::unique_ptr<ActionController> mActionController;
};

#endif // ICOMMAND_H
