#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#define RULES_PATH "rules.txt"

void Menu::StartGame()
{
}

void Menu::ShowRules()
{
	std::ifstream fin(RULES_PATH);

	if (!fin.is_open()) {
		throw std::runtime_error("Error opening file;");
	}

	try
	{
		char ch;
		while (fin.get(ch))
		{
			std::cout << ch;
		}
	}

	catch (const std::exception& ex)
	{
		std::cerr << "Exception caught: " << ex.what() << std::endl;
	}

	fin.close();

	std::cout << std::endl;

	(isPaused) ? ShowPauseMenu() : ShowMainMenu();

}

void Menu::ExitGame()
{
	std::cout << "Are you sure you want to exit the game?\tPress: y - yes / n - no" << std::endl;
	char result;
	std::cin >> result;
	
	if (result == 'y') exit(0);
}

void Menu::GoToMenu(MenuItem item)
{
	switch (item)
	{
	case MenuItem::NewGame: StartGame(); break;
	case MenuItem::Rules: ShowRules(); break;
	case MenuItem::Exit: ExitGame(); break;
	default: std::cout << "Menu item doesn't exist."; break;
	}
}

 void Menu::ShowMainMenu()
 {
	 isPaused = false;

	 std::cout << "MAIN MENU:\t" << "1. New Game\t" << "2. Rules\t" << "3. Exit" << std::endl;
	 std::cout << "Press button to continue..." << std::endl;
 }

 void Menu::ShowPauseMenu()
 {
	 isPaused = true;
 }
