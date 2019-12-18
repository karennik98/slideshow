#include "command_builder.h"
#include "commands.h"
#include "icommand.h"
#include "token.h"

#include <QRegExp>

#include <tuple>

ICommand* CommandBuilder::build()
{
    while(mBegin != mEnd)
    {
        CommandType type = getCommandType();

        switch (type) {
        case CommandType::add_rect:
        {
            eat();
            std::tuple<Position, Dimension, ID> args = getAddRectCommandArgs();
            //std::unique_ptr<ICommand> cmd {new AddRectCommand(args.first, args.second)}; // make_unique dont work
            //return cmd;
            return new AddRectCommand(std::get<0>(args), std::get<1>(args), std::get<2>(args));
        }
        case CommandType::unknown_type:
            return {}; // TODO meybe remove unknown_type
        }
    }
    return {};//TODO
}


CommandType CommandBuilder::getCommandType() const
{
    Q_ASSERT_X(current().type == TokenType::command, "Token type", "Wrong token type");

    switch (hash_function(current().name.toStdString().c_str())) {
        case static_cast<uint>(CommandType::add_rect): // TODO
            return  CommandType::add_rect;
        default:
            Q_ASSERT_X(false, "Command type", "Unknown token type");
    }
}

std::tuple<Position, Dimension, ID> CommandBuilder::getAddRectCommandArgs()
{
    Position pos;
    Dimension dim;
    ID id;

    for(; mBegin != mEnd; mBegin++)
    {
        if(mBegin->type == TokenType::option && mBegin->name == "center")
        {
           QPair<int, int> vals = getIntegerValues();
           pos.x = vals.first;
           pos.y = vals.second;
        }
        else if(mBegin->type == TokenType::option && mBegin->name == "size")
        {
           QPair<int, int> vals = getIntegerValues();
           dim.width = vals.first;
           dim.height = vals.second;
        }
        else if(mBegin->type == TokenType::option && mBegin->name == "id")
        {
            id = getIDValue();
        }
        else
        {
            Q_ASSERT_X(false, "Wrong parsing", "Wrong token type or name");
        }
    }

    return std::make_tuple(pos, dim, id);
}

QPair<int, int> CommandBuilder::getIntegerValues()
{
    int val_1;
    int val_2;

    eat();
    QRegExp valChackReg("\\d*[' '*','' '*]\\d*"); //  TODO check
    if(mBegin->type == TokenType::value && valChackReg.exactMatch(mBegin->name)) // TODO thing aboutn mBegin->name
    {
        QString value = mBegin->name;
        QString w;
        QString h;
        for( auto it = value.begin(); it != value.end(); it++)
        {
            if(*it ==',')
            {
                ++it;
                while(it != value.end()) {
                    h += *it++;
                }
                break;
            }
            else
            {
               w += *it;
            }
        }

        val_1= w.toInt();
        val_2 = h.toInt();
    }
    else
    {
        Q_ASSERT_X(false, "", "Wrong value type or input");
    }

    return qMakePair(val_1, val_2);
}

ID CommandBuilder::getIDValue()
{
    ID id;

    eat();
    QRegExp idCheck("\\d*");
    if(mBegin->type == TokenType::value && idCheck.exactMatch(mBegin->name))
    {
        QString value = mBegin->name;
        QString strId;
        for(const auto& el : value)
        {
            strId += el;
        }
        id = strId.toUInt();
    }
    else
    {
        Q_ASSERT_X(false, "","Wrong value type or input for id");
    }

    return id;
}

bool CommandBuilder::isCommandType() const
{
    return mBegin->type == TokenType::command;
}


Token CommandBuilder::current() const
{
    return *mBegin;
}

void CommandBuilder::eat()
{
    mBegin++;
}
