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
}

InputHandler::~InputHandler()
{
    delete button_ESC;
    delete button_1;
    delete button_2;
    delete button_3;
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
    case Button::Button_F1: button_3->Execute(); break;
    case Button::Button_F2: button_3->Execute(); break;
    case Button::Button_F3: button_3->Execute(); break;
    case Button::Button_F4: button_3->Execute(); break;
    default:
        break;
    }
}





