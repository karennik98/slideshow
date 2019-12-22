#include "command_controller.h"
#include "command_parser.h"
#include "command_builder.h"
#include "commands.h"
#include "utility.h"

#include <any>
#include <algorithm>

CommandController::CommandController()
    : mParser(std::move(new CommandParser))
    , mArgsBuilder(std::move(new ArgsBuilder))
   // , mCommandBuilder(std::move(new CommandBuilder))
{

}

void CommandController::registerCommand()
{
  mCommands[CommandType::add_rect] = std::make_unique<AddRectCommand>();
  //TODO add all commands
}


void CommandController::execute(const QString& line)
{
  QVector<Token> tokens = mParser->parse(line);

  std::any args = mArgsBuilder->getArgs(tokens);

  const auto command = std::find(mCommands.begin(), mCommands.end(), hash_function(tokens[0].name.toStdString().c_str()));

  command->second->execute(args);

//  mCommands.find(hash_function(tokens[0].name.toStdString().c_str()));
}
