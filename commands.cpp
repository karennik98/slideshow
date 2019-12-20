#include "commands.h"
#include "iobject.h"
#include "object.h"
#include "property.h"
#include "shapes.h"

#include <QDebug>

#include <memory>

AddRectCommand::AddRectCommand(Position pos, Dimension dim, ID id) : ICommand("add_rect")
{
    //TODO create object, call AddRecAction
    //std::unique_ptr<IObject> object (new Object(std::unique_ptr<ShapeProperty>(pos,dim,id), std::unique_ptr<Rect>()));
    IObject* object = new Object(new ShapeProperty(pos, dim, id), new Rect);

}
