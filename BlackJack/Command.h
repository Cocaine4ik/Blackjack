#pragma once
#include "Menu.h"
#include "GameMode.h"

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
    virtual void Execute() { Menu::GetInstance().ShowPauseMenu(); }
};

/**
 * @brief *
*/
class ShowExitMenuCommand : public Command
{
public:
    virtual void Execute() { Menu::GetInstance().ShowExitMenu(); }
};

/**
 * @brief 
*/
class ShowRulesCommand : public Command
{
public:
    virtual void Execute()
    {
        Menu::GetInstance().ShowRules();

        if (GameMode::GetInstance().GetGameState() == GameState::Pause) {
            Menu::GetInstance().ShowPauseMenu();
        }
        else Menu::GetInstance().ShowMainMenu();
    }
};

class StartNewGameCommand : public Command
{
public:
    virtual void Execute() { GameMode::GetInstance().StartGame(); }
};
