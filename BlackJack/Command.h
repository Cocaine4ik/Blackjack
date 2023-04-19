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
    virtual void Execute() { ShowPauseMenu(); }

    void ShowPauseMenu() 
    { 
        Menu::GetInstance().ShowPauseMenu();
    }
};

/**
 * @brief *
*/
class ShowExitMenuCommand : public Command
{
public:
    virtual void Execute() { ShowExitMenu(); }

    void ShowExitMenu() 
    {
        Menu::GetInstance().ShowExitMenu();
    }
};

/**
 * @brief 
*/
class ShowRulesCommand : public Command
{
public:
    virtual void Execute() { ShowRules(); }

    void ShowRules()
    {
        Menu::GetInstance().ShowRules();

        if (GameMode::GetInstance().GetGameState() == GameState::Pause) {
            Menu::GetInstance().ShowPauseMenu();
        }
        else Menu::GetInstance().ShowMainMenu();

    }
};