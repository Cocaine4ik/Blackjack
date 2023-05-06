#include "InputHandler.h"
#include "Command.h"
#include "Singleton.h"
#include <iostream>

InputHandler::InputHandler()
{
    // input handler in not blocked by default
    isBlocked = false;

    // allocate memory for each button (command)

    button_SPACE = new ContinueCommand();
    button_1 = new StartNewGameCommand();
    button_2 = new ShowRulesCommand();
    button_3 = new ExitGameCommand();
    button_Z = new MinBetCommand();
    button_X = new MediumBetCommand();
    button_C = new LargeBetCommand();
    button_V = new MaxBetCommand();
    button_Q = new HitCommand();
    button_W = new StandCommand();
    button_E = new DoubleDownCommand();
    button_R = new SurrenderCommand();
    button_Y = new ConfirmExitCommand();
    button_N = new CancelExitCommand();
}

InputHandler::~InputHandler()
{
    // delete dynamically allocated memoty for each button (command)
    delete button_SPACE;
    delete button_1;
    delete button_2;
    delete button_3;
    delete button_Z;
    delete button_X;
    delete button_C;
    delete button_V;
    delete button_Q;
    delete button_W;
    delete button_E;
    delete button_R;
    delete button_Y;
    delete button_N;
}

void InputHandler::HandleInput(Button button)
{
    if (IsBlocked()) return;

    switch (button)
    {
    case Button::Button_SPACE: button_SPACE->Execute(); break;
    case Button::Button_1: button_1->Execute(); break;
    case Button::Button_2: button_2->Execute(); break;
    case Button::Button_3: button_3->Execute(); break;
    case Button::Button_Z: button_Z->Execute(); break;
    case Button::Button_X: button_X->Execute(); break;
    case Button::Button_C: button_C->Execute(); break;
    case Button::Button_V: button_V->Execute(); break;
    case Button::Button_Q: button_Q->Execute(); break;
    case Button::Button_W: button_W->Execute(); break;
    case Button::Button_E: button_E->Execute(); break;
    case Button::Button_R: button_R->Execute(); break;
    case Button::Button_Y: button_Y->Execute(); break;
    case Button::Button_N: button_N->Execute(); break;
    default: 
        // std::cout << "Button wasn't recognized" << static_cast<int>(button) << std::endl;
        break;
    }
}





