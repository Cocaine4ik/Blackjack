#include "InputHandler.h"
#include "Command.h"
#include "Singleton.h"

InputHandler::InputHandler()
{
    isBlocked = false;

    button_ESC = new ShowPauseMenuCommand();
    button_1 = new StartNewGameCommand();
    button_2 = new ShowRulesCommand();
    button_3 = new ShowExitMenuCommand();
    button_Z = new MinBetCommand();
    button_X = new MediumBetCommand();
    button_C = new LargeBetCommand();
    button_V = new MaxBetCommand();
}

InputHandler::~InputHandler()
{
    delete button_ESC;
    delete button_1;
    delete button_2;
    delete button_3;
    delete button_Z;
    delete button_X;
    delete button_C;
    delete button_V;
}

void InputHandler::HandleInput(Button button)
{
    switch (button)
    {
    case Button::Button_ESC: button_ESC->Execute(); break;
    case Button::Button_0: button_0->Execute(); break;
    case Button::Button_1: button_1->Execute(); break;
    case Button::Button_2: button_2->Execute(); break;
    case Button::Button_3: button_3->Execute(); break;
    case Button::Button_Z: button_Z->Execute(); break;
    case Button::Button_X: button_X->Execute(); break;
    case Button::Button_C: button_C->Execute(); break;
    case Button::Button_V: button_V->Execute(); break;
    default:
        break;
    }
}





