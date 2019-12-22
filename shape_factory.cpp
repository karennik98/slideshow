#include "shape_factory.hpp"
#include "shapes.h"

ShapeFactory& ShapeFactory::instance()
{
    static ShapeFactory factory;
    return factory;
}

std::unique_ptr<IShape> ShapeFactory::create(ShapeName name) const
{
  switch (name) {
    case ShapeName::Rect: {
        return std::make_unique<Rect>("rect");
    }
    case ShapeName::Circle: {
        return std::make_unique<Circle>("circle");
    }
    case ShapeName::Triangle: {
        return std::make_unique<Triangle>("triangle");
    }
  }
}
