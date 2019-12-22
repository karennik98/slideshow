#ifndef ACTIONS_H
#define ACTIONS_H

#include "iaction.h"

#include <memory>

class Slide;
class SlideShow;

class AddRectAction : public IAction
{
public:
    AddRectAction(std::shared_ptr<Slide> slide, std::unique_ptr<IObject> object);
    virtual IAction* apply() override;
private:
    std::shared_ptr<Slide> mSlide;
    std::unique_ptr<IObject> mObject;
};

#endif // ACTIONS_H
