#include <iostream>
#include <conio.h>
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

	// Change console color scheme
	system("color 17");

	// Show welcome message and menu

    GameMode::GetInstance().Welcome();

	char buttonPressed;

	// Handle input and execute commands

	while (true) {

        buttonPressed = _getch();
        
        InputHandler::GetInstance().HandleInput(static_cast<Button>(buttonPressed));
	}

}