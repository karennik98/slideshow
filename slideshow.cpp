#include "slideshow.h"

void SlideShow::addSlide(std::unique_ptr<Slide> slide)
{
  mSlides.push_back(std::move(slide));
}
