#pragma once

#include "shape_names_enum.hpp"

class IShape;

#include <memory>

class ShapeFactory
{
public:
  static ShapeFactory& instance();
  std::unique_ptr<IShape> create(ShapeName name) const;
private:
    ShapeFactory();
};
