#pragma once
#include "UIController.h"
#include "GameMode.h"
#include "Player.h"

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
    virtual void Execute() { UIController::GetInstance().ShowPauseMenu(); }
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

class SmallBetCommand : public Command 
{
public:
    virtual void Execute()
    {
        auto& player = GameMode::GetInstance().GetPlayer();

        player.Bet(100);
    }
};
