#pragma once
class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

class CallMainMenuCommand : public Command
{
public:
    virtual void Execute() { CallMenu(); }
    void CallMenu();
};