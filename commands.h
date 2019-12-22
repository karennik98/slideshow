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
    AddRectCommand();
    virtual void execute(std::any args) override;
private:
    std::shared_ptr<Slide> mSlide;
};


#endif // COMMANDS_H
