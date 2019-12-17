#ifndef COMMANDS_H
#define COMMANDS_H

#include "icommand.h"
#include "basic_types.h"

class AddRectCommand : public ICommand
{
public:
    AddRectCommand(Position pos, Dimension dim);
    virtual void execute() override;
};


#endif // COMMANDS_H
