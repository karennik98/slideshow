#include "commands.h"
#include "iobject.h"
#include "object.h"
#include "property.h"
#include "iaction.h"
#include "actions.h"
#include "shapes.h"

#include <QDebug>

#include <memory>
#include <tuple>

AddRectCommand::AddRectCommand() : ICommand("add_rect")
{
    //TODO create object, call AddRecAction
    //std::unique_ptr<IObject> object (new Object(std::unique_ptr<ShapeProperty>(pos,dim,id), std::unique_ptr<Rect>()));
}

void AddRectCommand::execute(std::any args)
{
  const auto rectArgs = std::any_cast<std::tuple<Position, Dimension, ID>>(args);
  IObject* object = new Object(new ShapeProperty(std::get<0>(rectArgs), std::get<1>(rectArgs), std::get<2>(rectArgs)), new Rect);


}
