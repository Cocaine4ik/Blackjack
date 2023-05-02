#pragma once
#include "Singleton.h"

class Command;

enum class Button 
{
    Button_0 = 48,
    Button_1 = 49,
    Button_2 = 50,
    Button_3 = 51,
    Button_Q = 113,
    Button_W = 119,
    Button_E = 101,
    Button_R = 114,
    Button_T = 116,
    Button_Y = 89,
    Button_N = 78,
    Button_Z = 122,
    Button_X = 120,
    Button_C = 99,
    Button_V = 118
};

class InputHandler : public Singleton <InputHandler>
{
    friend class Singleton<InputHandler>;

private:
    InputHandler();
    ~InputHandler();

public:
    void HandleInput(Button button);

    bool IsBlocked() const { return isBlocked; }
    void Block(bool value) { isBlocked = value; }


private:
    bool isBlocked;

    Command* button_0;
    Command* button_1;
    Command* button_2;
    Command* button_3;
    Command* button_Y;
    Command* button_N;
    Command* button_Z;
    Command* button_X;
    Command* button_C;
    Command* button_V;
    Command* button_Q;
    Command* button_W;
    Command* button_E;
    Command* button_R;
    Command* button_T;
};
