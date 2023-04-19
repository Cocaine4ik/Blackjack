#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>

#define RULES_PATH "rules.txt"

void Menu::ShowMainMenu()
{
    std::cout << "MAIN MENU:\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void Menu::ShowPauseMenu()
{
    std::cout << "PAUSE MENU:\t" << "0 - Continue\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void Menu::ShowGameMenu()
{
    std::cout << "GAME MENU:\t" << "H - Hit\t" << "1New Game\t" << "2. Rules\t" << "3. Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void Menu::ShowExitMenu()
{
	std::cout << "Are you sure you want to exit the game?\tPress: y - yes / n - no" << std::endl;
}

 void Menu::ShowRules()
 {
     system("cls");
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
 }