#ifndef ACTIONCONTROLLER_H
#define ACTIONCONTROLLER_H

#include <QStack>

class IAction;

class ActionController
{
public:
    ActionController();
    void undo();
    void redo();
    void action(); // TODO function name
private:
    QStack<IAction*> mUndoStack;
    QStack<IAction*> mRedoStack;
};

#endif // ACTIONCONTROLLER_H
