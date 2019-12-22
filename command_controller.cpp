#include "command_controller.h"
#include "command_parser.h"
#include "command_builder.h"

CommandController::CommandController()
    : mParser(std::move(new CommandParser))
    , mCommandBuilder(std::move(new CommandBuilder))
{

}


void CommandController::execute(const QString& line)
{
    m
}
