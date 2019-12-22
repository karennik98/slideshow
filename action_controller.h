#ifndef ACTIONCONTROLLER_H
#define ACTIONCONTROLLER_H

#include <QStack>

#include <memory>

class IAction;

class ActionController
{
public:
    ActionController() = default;
    void doAction(std::unique_ptr<IAction> action);
    void undo();
    void redo();
private:
    QStack<IAction*> mUndoStack;
    QStack<IAction*> mRedoStack;
};

#endif // ACTIONCONTROLLER_H
