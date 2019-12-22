#include "actions.h"
#include "slide.h"
#include "slideshow.h"

AddRectAction::AddRectAction(std::shared_ptr<Slide> slide, std::unique_ptr<IObject> object)
    : mSlide(slide)
{
}

IAction* AddRectAction::apply()
{
  mSlide->addObject(std::move(mObject));
}
