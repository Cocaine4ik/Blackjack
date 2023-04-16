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
	static void GoToMenu(MenuItem item);
	static void ShowMenu();

private:
	static void StartGame();
	static void ShowRules();
	static void ExitGame();
};

