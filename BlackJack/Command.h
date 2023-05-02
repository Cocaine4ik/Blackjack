#pragma once
#include "UIController.h"
#include "GameMode.h"
#include "GameConfig.h"

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

        if (gameState == GameState::Menu)
        {
            uiController.ShowRules();
            uiController.ShowMenu();
        }
    }
};

class StartNewGameCommand : public Command
{
public:
    virtual void Execute()
    {
        GameMode::GetInstance().StartGame();
    }
};

class MinBetCommand : public Command 
{
public:
    virtual void Execute(){ GameMode::GetInstance().PlaceBet(GameConfig::GetInstance().GetMinBet()); }
};

class MediumBetCommand : public MinBetCommand
{
public:
    virtual void Execute() { GameMode::GetInstance().PlaceBet(GameConfig::GetInstance().GetMediumBet()); }
};

class LargeBetCommand : public MinBetCommand
{
public:
        virtual void Execute() { GameMode::GetInstance().PlaceBet(GameConfig::GetInstance().GetLargeBet()); }
};

class MaxBetCommand : public MinBetCommand
{
public:
    virtual void Execute() { GameMode::GetInstance().PlaceBet(GameConfig::GetInstance().GetMaxBet()); }
};

class HitCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Hit(); }
};

class StandCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Stand(); }
};

class DoubleDownCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().DoubleDown(); }
};


class SplitCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Split(); }
};

class SurrenderCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Surrender(); }
};

class ConfirmExitCommand : public Command
{

};

class CancelExitCommand : public Command
{

};