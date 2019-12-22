#include "commands.h"
#include "iobject.h"
#include "slide.h"
#include "object.h"
#include "property.h"
#include "iaction.h"
#include "actions.h"
#include "shapes.h"
#include "basic_types.h"

#include <QDebug>

#include <memory>
#include <tuple>

AddRectCommand::AddRectCommand() : ICommand("add_rect")
{

}

void AddRectCommand::execute(std::any args)
{
  try {
    const auto rectArgs = std::any_cast<std::tuple<Position, Dimension, ID>>(args);

    std::unique_ptr<PropertyBase> property (new ShapeProperty(std::get<0>(rectArgs), std::get<1>(rectArgs), std::get<2>(rectArgs)));
    std::unique_ptr<IShape> shape (new Rect());

    std::unique_ptr<IObject> object (new Object(std::move(property), std::move(shape)));

    std::unique_ptr<IAction> action (new AddRectAction(mSlide, std::move(object)));

    mActionController->doAction(std::move(action));

  } catch (std::bad_any_cast& badCast) {
      qDebug() << badCast.what();
  }
}

RemoveRectCommand::RemoveRectCommand() : ICommand("move_rect")
{

}

void RemoveRectCommand::execute(std::any args)
{
  try {
    const auto moveArgs = std::any_cast<std::tuple<ID>>(args); //maybe not need tuple

    std::uni

  } catch (std::bad_any_cast& badCast) {
      qDebug() << badCast.what();
  }
}












