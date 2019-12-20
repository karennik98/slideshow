#ifndef APPLICATION_H
#define APPLICATION_H

#include "command_controller.h"
#include "action_controller.h"
#include "slideshow.h"
#include "slide.h"

#include <memory>

class ShapeLibrary;

class Application
{
public:
    Application() = default;
    Application(int argv, char* argc[]);
    bool run();
private:
    std::unique_ptr<CommandController> mCommandController;
    std::unique_ptr<ActionController> mActionController;
    std::unique_ptr<SlideShow> mSlideShow;
    std::unique_ptr<ShapeLibrary> mShapeLibrary;
};

#endif // APPLICATION_H
