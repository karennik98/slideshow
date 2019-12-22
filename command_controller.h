#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include "args_builder.hpp"
#include "command_type_enums.h"

#include <QVector>
#include <QString>

#include <memory>
#include <unordered_map>

class ICommand;
class CommandParser;
class CommandBuilder;

class CommandController
{
public:
    CommandController();
    void registerCommand();
    void execute(const QString& line);
private:
    std::unordered_map<CommandType, std::unique_ptr<ICommand>> mCommands;
    std::unique_ptr<CommandParser> mParser;
    std::unique_ptr<ArgsBuilder> mArgsBuilder;
    //std::unique_ptr<CommandBuilder> mCommandBuilder;
};

#endif // COMMANDCONTROLLER_H
