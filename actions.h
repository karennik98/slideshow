#ifndef ACTIONS_H
#define ACTIONS_H

#include "iaction.h"

#include <memory>

class Slide;
class SlideShow;

class AddRectAction : public IAction
{
public:
    virtual IAction* apply(/*IObject* object*/) override;
private:
    std::shared_ptr<Slide*> mSlide;
    std::shared_ptr<SlideShow*> mSlideShow;
};

#endif // ACTIONS_H
