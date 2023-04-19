#include "InputHandler.h"
#include "Command.h"

InputHandler::~InputHandler()
{
    delete button_ESC;
}

void InputHandler::HandleInput(Button button)
{
    switch (button)
    {
    case Button::Button_ESC: button_ESC->Execute(); break;
    case Button::Button_0: button_0->Execute(); break;
    case Button::Button_1: button_0->Execute(); break;
    case Button::Button_2: button_2->Execute(); break;
    case Button::Button_3: button_3->Execute(); break;
    default:
        break;
    }
}

InputHandler::InputHandler()
{
    button_ESC = new ShowPauseMenuCommand();
    button_2 = new ShowRulesCommand();
    button_3 = new ShowExitMenuCommand();

}
