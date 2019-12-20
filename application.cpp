#include "application.h"
#include "shape_library.h"

#include <QTextStream>
#include <QString>

Application::Application(int argv, char* argc[])
    : mCommandController(new CommandController())
    , mActionController(new ActionController())
    , mSlideShow(new SlideShow())
    , mShapeLibrary(new ShapeLibrary())
{

}

bool Application::run()
{
    while (true)
    {
        QTextStream inputStream(stdin);
        QString command = inputStream.readLine();
        mCommandController->inputHandler(command);
    }
}
