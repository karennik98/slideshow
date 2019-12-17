#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H

#include "token.h"
#include "command_type_enums.h"

#include <QVector>
#include <QPair>

#include <memory>

struct Position;
struct Dimension;
class ICommand;

class CommandBuilder
{
public:
    CommandBuilder(const QVector<Token>& tokens)
        : mBegin(tokens.begin())
        , mEnd(tokens.end())
    {}
    ICommand* build();
private:
    CommandType getCommandType() const;
    QPair<Position, Dimension> getAddRectCommandArgs();
    QPair<int, int> getIntegerValues();

    bool isCommandType() const;

    Token current() const;
    void eat();
private:
    QVector<Token>::const_iterator mBegin;
    QVector<Token>::const_iterator mEnd;
};

#endif // COMMANDBUILDER_H
