#include "UIController.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "GameMode.h"
#include "GameConfig.h"

#define RULES_PATH "rules.txt"

void UIController::ShowMainMenu()
{
    GameMode::GetInstance().SetGameState(GameState::Menu);

    std::cout << "MAIN MENU:\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void UIController::ShowPauseMenu()
{
    GameMode::GetInstance().SetGameState(GameState::Pause);

    std::cout << "PAUSE MENU:\t" << "0 - Continue\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void UIController::ShowGUI()
{
    std::cout << "GAME MENU:\t" << "H - Hit\t" << "1New Game\t" << "2. Rules\t" << "3. Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void UIController::ShowExitConfirmation()
{
	std::cout << "Are you sure you want to exit the game?\tPress: y - yes / n - no" << std::endl;
}

void UIController::ShowPlayerStat(const std::string& playerName, int money, int score)
{
    std::cout << "***************************************************" << std::endl;
    std::cout << "* Name: " << playerName << "\t" << "Money: " << money << "\t" << "Score: " << score << " *" << std::endl;
    std::cout << "***************************************************" << std::endl;
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
