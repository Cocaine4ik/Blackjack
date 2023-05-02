#include <iostream>
#include <string>
#include <conio.h>
#include "UIController.h"
#include "InputHandler.h"
#include "GameMode.h"

int main()
{
	/*
	*0 = Black              8 = Grey
	* 1 = Blue				9 = L. Blue 
	* 2 = Green				A = L. Green
	* 3 = Aqua				B = L. Aqua
	* 4 = Red				C = L. Red
	* 5 = Purple			D = L. Purple
	* 6 = Yellow			E = L. Yellow
	* 7 = White             Bright White
	*/

	system("color 17");

	std::cout << "Welcome to Black Jack Console Game" << std::endl << std::endl;

	UIController::GetInstance().ShowMenu();

	char buttonPressed;

	while (true) {

        if (!InputHandler::GetInstance().IsBlocked()) {

            buttonPressed = _getch();
            InputHandler::GetInstance().HandleInput(static_cast<Button>(buttonPressed));
        }
	}

}