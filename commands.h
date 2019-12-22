#ifndef COMMANDS_H
#define COMMANDS_H

#include "icommand.h"
#include "basic_types.h"
#include "declaration.h"

#include <memory>

class Slide;

class AddRectCommand : public ICommand
{
public:
    AddRectCommand(Position pos, Dimension dim, ID id);
    virtual void execute() override;
private:
    std::shared_ptr<Slide> mSlide;
};


#endif // COMMANDS_H
