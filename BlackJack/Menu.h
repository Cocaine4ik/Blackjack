#pragma once

enum class MenuItem {
	NewGame = 49,
	Rules = 50,
	Exit = 51
};

class Menu
{
private:
	bool isPaused = false;

public:
	static Menu& GetInstance() { static Menu instance; return instance; };

	void GoToMenu(MenuItem item);
	void ShowMainMenu();
	void ShowPauseMenu();

private:
	Menu() {};
	Menu(const Menu&) = delete;
	Menu& operator = (const Menu&) = delete;

	void StartGame();
	void ShowRules();
	void ExitGame();
};

