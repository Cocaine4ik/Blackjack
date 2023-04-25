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
    virtual void Execute(){ PlaceBet(GameConfig::GetInstance().GetMinBet()); }

protected:
    void PlaceBet(const int& amount) 
    {
        auto& gameMode = GameMode::GetInstance();

        auto& player = gameMode.GetPlayer();
        auto bet = player.Bet(amount);
        gameMode.SetBank(bet);

        gameMode.StartRound();
    }
};

class MediumBetCommand : public MinBetCommand
{
public:
    virtual void Execute() { PlaceBet(GameConfig::GetInstance().GetMediumBet()); }
};

class LargeBetCommand : public MinBetCommand
{
public:
        virtual void Execute() { PlaceBet(GameConfig::GetInstance().GetLargeBet()); }
};

class MaxBetCommand : public MinBetCommand
{
public:
    virtual void Execute() { PlaceBet(GameConfig::GetInstance().GetMaxBet()); }
};