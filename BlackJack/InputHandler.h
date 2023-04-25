#pragma once
#include "Singleton.h"

class Command;

enum class Button 
{
    Button_ESC = 27,
    Button_0 = 48,
    Button_1 = 49,
    Button_2 = 50,
    Button_3 = 51,
    Button_H = 72,
    Button_S = 83,
    Button_D = 68,
    Button_B = 66,
    Button_Y = 89,
    Button_N = 78,
    Button_Z = 90,
    Button_X = 88,
    Button_C = 67,
    Button_V = 86
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

    Command* button_ESC;
    Command* button_0;
    Command* button_1;
    Command* button_2;
    Command* button_3;
    Command* button_H;
    Command* button_S;
    Command* button_D;
    Command* button_B;
    Command* button_Y;
    Command* button_N;
    Command* button_Z;
    Command* button_X;
    Command* button_C;
    Command* button_V;

};
