#ifndef COMMANDS_H
#define COMMANDS_H

#include "icommand.h"
#include "basic_types.h"
#include "declaration.h"

class AddRectCommand : public ICommand
{
public:
    AddRectCommand(Position pos, Dimension dim, ID id);
    virtual void execute() override;
};


#endif // COMMANDS_H
