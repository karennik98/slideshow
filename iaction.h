#ifndef IACTION_H
#define IACTION_H

class IObject;

class IAction
{
public:
    IAction() = default;
    virtual IAction* apply() = 0;
};

#endif // IACTION_H
