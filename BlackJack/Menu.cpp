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
}

void Menu::ExitGame()
{

	exit(0);
	std::cout << "Are you sure you want to exit the game?\tPress: y - yes / n - no |" << std::endl;
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

 void Menu::ShowMenu()
 {
 }
