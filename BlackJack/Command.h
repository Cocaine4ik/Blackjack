#pragma once
#include "UIController.h"
#include "GameMode.h"
#include "Player.h"
#include "GameConfig.h"
#include <iostream>

/**
 * @brief 
*/
class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

/**
 * @brief 
*/
class ShowPauseMenuCommand : public Command
{
public:
    virtual void Execute() 
    { 
        if (GameMode::GetInstance().GetGameState() != GameState::Menu) 
        {
            UIController::GetInstance().ShowPauseMenu();
        }
    }
};

/**
 * @brief *
*/
class ShowExitMenuCommand : public Command
{
public:
    virtual void Execute() { UIController::GetInstance().ShowExitConfirmation(); }
};

/**
 * @brief 
*/
class ShowRulesCommand : public Command
{
public:
    virtual void Execute()
    {
        auto gameState = GameMode::GetInstance().GetGameState();
        auto& uiController = UIController::GetInstance();

        if (gameState == GameState::Pause) 
        {
            uiController.ShowRules();
            uiController.ShowPauseMenu();
        }
        else if (gameState == GameState::Menu)
        {
            uiController.ShowRules();
            uiController.ShowMainMenu();
        }
    }
};

class StartNewGameCommand : public Command
{
public:
    virtual void Execute()
    {
        auto& gameMode = GameMode::GetInstance();
        auto gameState = gameMode.GetGameState();

        if(gameState == GameState::Menu || gameState == GameState::Pause) gameMode.StartGame();
    }
};

class MinBetCommand : public Command 
{
public:
    virtual void Execute()
    {
        auto& player = GameMode::GetInstance().GetPlayer();

        player.Bet(GameConfig::GetInstance().GetMinBet());

        std::cout << "test";
    }
};

class MediumBetCommand : public Command
{
public:
    virtual void Execute()
    {
        auto& player = GameMode::GetInstance().GetPlayer();

        player.Bet(GameConfig::GetInstance().GetMediumBet());
    }
};

class LargeBetCommand : public Command
{
public:
    virtual void Execute()
    {
        auto& player = GameMode::GetInstance().GetPlayer();

        player.Bet(GameConfig::GetInstance().GetLargeBet());
    }
};

class MaxBetCommand : public Command
{
public:
    virtual void Execute()
    {
        auto& player = GameMode::GetInstance().GetPlayer();
        auto& bank = G
        player.Bet(GameConfig::GetInstance().GetMaxBet());
    }
};