#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "icommand.h"

#include <QString>

class CommandParser
{
public:
    CommandParser();
    ICommand* parse(QString commandLine);
private:
};

#endif // COMMANDPARSER_H
