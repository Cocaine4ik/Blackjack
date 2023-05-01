#pragma once
#include "Singleton.h"
#include <string>

class UIController : public Singleton <UIController>
{
public:
	void ShowMainMenu();
	void ShowPauseMenu();
    void ShowGUI();
    void ShowExitConfirmation();

	void ShowPlayerStat(const std::string& playerName, int money, int score, bool isDealer = false);
	void ShowBets();

    void ShowRules();

};

