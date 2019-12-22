#pragma once

#include "token.h"
#include "declaration.h"
#include "command_type_enums.h"

#include <QVector>

#include <tuple>
#include <any>

struct Position;
struct Dimension;

class ArgsBuilder
{
public:
  ArgsBuilder() = default;
  ArgsBuilder(const QVector<Token>& tokens)
    : mBegin(tokens.cbegin())
    , mEnd(tokens.cend())
  {}

  std::any getArgs();
  std::any getArgs(const QVector<Token>& tokens);

private:
  CommandType getCommandType() const;

  std::tuple<Position, Dimension, ID> getAddRectCommandArgs();

  QPair<int, int> getIntegerValues();
  ID getIDValue();

  Token current() const;
  void eat();
private:
  QVector<Token>::const_iterator mBegin;
  QVector<Token>::const_iterator mEnd;
};

