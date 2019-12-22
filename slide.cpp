#include "slide.h"

void Slide::addObject(std::unique_ptr<IObject> object)
{
  mObjects.push_back(std::move(object));
}
