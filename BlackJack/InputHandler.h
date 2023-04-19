#pragma once

class Command;

enum class Button {
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
    Button_N = 78
};

class InputHandler
{
public:
    ~InputHandler();
    static InputHandler& GetInstance() { static InputHandler instance; return instance; };
    void HandleInput(Button button);

    bool IsBlocked() const { return isBlocked; }
    void Block(bool value) { isBlocked = value; }

private:
    bool isBlocked = false;

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

    InputHandler();
    InputHandler(const InputHandler&) = delete;
    InputHandler& operator = (const InputHandler&) = delete;

};
