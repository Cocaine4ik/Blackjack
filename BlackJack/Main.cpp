#include <iostream>
#include <string>
#include <conio.h>
#include "Menu.h"
#include "InputHandler.h"
#include "GameMode.h"

int main()
{
	/*
	* BlackJack game
	*/

	/*
	* 1. Set player name => Add player to the game with some money
	* 2. Add diller to the game
	* 3. Make a bet (min / max bets or templates)
	* 4. Shuffle deck
	* 4. Dealer take two card, on card he show another if not faceup
	* 5. Player take two card
	* 6. Player can Hit, Stand, Surrender DoubleDown or split if he have pair
	* 7. Depens of his cards, dealer can make a decion about taking more cards
	* 8. If player have black  automaticly win
	* 9. If both players Stand they show the cards
	* 10. We will sum points using stl accumulate
	*/

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

    GameMode::GetInstance().SetGameState(GameState::Menu);
	Menu::GetInstance().ShowMainMenu();

	char buttonPressed;

	while (true) {

        if (!InputHandler::GetInstance().IsBlocked()) {

            buttonPressed = _getch();
            InputHandler::GetInstance().HandleInput(static_cast<Button>(buttonPressed));
        }
	}

}