#include "actions.h"
#include "slide.h"
#include "slideshow.h"

AddRectAction::AddRectAction(std::shared_ptr<Slide> slide, std::shared_ptr<SlideShow> slideshow)
    : mSlide(slide)
    , mSlideShow(slideshow)
{
}

IAction* AddRectAction::apply(IObject *object)
{

}
