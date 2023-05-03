#pragma once
#include "Singleton.h"
#include <string>

class UIController : public Singleton <UIController>
{
public:
    void ShowGUI();
    void ShowDealerUI();
    void ShowExitConfirmation();

	void ShowPlayerStat(const std::string& playerName, int money, int score, bool isDealer = false);
	void ShowBets();

    void ShowRules();

};

