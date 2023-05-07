#pragma once
#include "GameMode.h"
#include "GameConfig.h"

#define MIN_BET 100
#define MEDIUM_BET 250
#define LARGE_BET 500
#define MAX_BET 1000

/**
 * @brief Base command class
*/
class Command
{
public:
    /**
     * @brief Default virtual destructor
    */
    virtual ~Command() {}

    /**
     * @brief Abstract method for command execution
    */
    virtual void Execute() = 0;
};

/**
 * @brief Exit Game Command
*/
class ExitGameCommand : public Command
{
    virtual void Execute() override { GameMode::GetInstance().ExitGame(); }
};

/**
 * @brief Show Game Rules Command
*/
class ShowRulesCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().ShowRules(); }
};

/**
 * @brief Start New Game Command
*/
class StartNewGameCommand : public Command
{
    virtual void Execute() override{ GameMode::GetInstance().StartGame(); }
};

/**
 * @brief Continue Current Game Command
*/
class ContinueCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().ContinueGame(); }
};

/**
 * @brief Set Minimum Bet Command
*/
class MinBetCommand : public Command 
{
    virtual void Execute(){ GameMode::GetInstance().PlaceBet(MIN_BET); }
};

/**
 * @brief Set Medium Bet Command
*/
class MediumBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(MEDIUM_BET); }
};

/**
 * @brief Set Large Bet Command
*/
class LargeBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(LARGE_BET); }
};

/**
 * @brief Set Maximum Bet Command
*/
class MaxBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(MAX_BET); }
};

/**
 * @brief Hit Command
*/
class HitCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Hit(); }
};

/**
 * @brief Stand Command
*/
class StandCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Stand(); }
};

/**
 * @brief Double Down Command
*/
class DoubleDownCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().DoubleDown(); }
};

/**
 * @brief Surrender Command
*/
class SurrenderCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Surrender(); }
};



