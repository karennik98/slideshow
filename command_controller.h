#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QVector>
#include <QMap>
#include <QString>

#include <memory>

class ICommand;
class CommandParser;
class CommandBuilder;

class CommandController
{
public:
    CommandController();
    void execute(const QString& line);
private:
    QMap<QString, std::unique_ptr<ICommand>> mCommands;
    std::unique_ptr<CommandParser> mParser;
    std::unique_ptr<CommandBuilder> mCommandBuilder;
};

#endif // COMMANDCONTROLLER_H
