#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QVector>

#include <memory>

class ICommand;
class CommandParser;
class CommandBuilder;

class CommandController
{
public:
    CommandController();
private:
    QVector<ICommand*> mCommands;
    //std::unique_ptr<CommandParser> mParser;
    std::unique_ptr<CommandBuilder> mCommandBuilder;
};

#endif // COMMANDCONTROLLER_H
