#pragma once
#include "GameMode.h"
#include "GameConfig.h"
#include <cstdlib>

#define MIN_BET 100
#define MEDIUM_BET 250
#define LARGE_BET 500
#define MAX_BET 1000

/**
 * @brief Base
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
class ExitGameCommand : public Command
{
    virtual void Execute() override { GameMode::GetInstance().ExitGame(); }
};

/**
 * @brief 
*/
class ShowRulesCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().ShowRules(); }
};

class StartNewGameCommand : public Command
{
    virtual void Execute() override{ GameMode::GetInstance().StartGame(); }
};

class ContinueCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().ContinueGame(); }
};

class MinBetCommand : public Command 
{
    virtual void Execute(){ GameMode::GetInstance().PlaceBet(MIN_BET); }
};

class MediumBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(MEDIUM_BET); }
};

class LargeBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(LARGE_BET); }
};

class MaxBetCommand : public MinBetCommand
{
    virtual void Execute() { GameMode::GetInstance().PlaceBet(MAX_BET); }
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

class SurrenderCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Surrender(); }
};

class ConfirmExitCommand : public Command
{
    virtual void Execute() { exit(0); }
};

class CancelExitCommand : public Command
{
    virtual void Execute() { GameMode::GetInstance().Surrender(); }
};

