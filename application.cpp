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

QString Application::readLine() const
{
    QTextStream inputStream(stdin);
    return inputStream.readLine();
}

bool Application::run()
{
    while (true)
    {
        QString line = readLine();
        mCommandController->execute(line);
        //mCommandController->inputHandler(command);
    }
}
