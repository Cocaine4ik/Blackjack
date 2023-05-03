#include "UIController.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "GameMode.h"
#include "GameConfig.h"

#define RULES_PATH "rules.txt"

void UIController::ShowGUI()
{
    std::cout << std::endl;
    std::cout << "GAME MENU:\t" << "Q - Hit\t\t" << "W - Stand\t" << "E - Double Down\t\t" << "R - Surrender" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
    std::cout << std::endl;
}

void UIController::ShowDealerUI()
{
    std::cout << std::endl;
    std::cout << "...DEALER TURN..." << std::endl;
    std::cout << std::endl;
}

void UIController::ShowExitConfirmation()
{
	std::cout << "Are you sure you want to exit the game?\tPress: y - yes / n - no" << std::endl;
}

void UIController::ShowPlayerStat(const std::string& playerName, int money, int score, bool isDealer)
{

    std::cout << std::endl;
    std::cout << "***************************************************" << std::endl;
    std::cout << "* Name: " << playerName << "\t" << "Money: " << money << "\t" << "Score: " << score << " *" << std::endl;
    std::cout << "***************************************************" << std::endl;
    std::cout << std::endl;
}


void UIController::ShowBets()
{
    using namespace std::string_literals;

    auto& config = GameConfig::GetInstance();

    std::string str = "Make you bet:\tZ - "s + std::to_string(config.GetMinBet())
        + "$\tX - "s + std::to_string(config.GetMediumBet())
        + "$\tC - "s + std::to_string(config.GetLargeBet())
        + "$\tV - "s + std::to_string(config.GetMaxBet()) + "$"s;
    
    std::cout << str;
}

 void UIController::ShowRules()
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
