#include "action_controller.h"
#include "iaction.h"
#include "actions.h"

void ActionController::doAction(std::unique_ptr<IAction> action)
{
  mUndoStack.push(action->apply());
}
