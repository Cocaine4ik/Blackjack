#pragma once

class Menu
{
public:
	static Menu& GetInstance() { static Menu instance; return instance; };

	void ShowMainMenu();
	void ShowPauseMenu();
    void ShowGameMenu();
    void ShowExitMenu();

    void ShowRules();
private:
	Menu() {};
	Menu(const Menu&) = delete;
	Menu& operator = (const Menu&) = delete;
};

