#pragma once
#include "Singleton.h"
#include <utility>
#include <string>

typedef std::pair<std::string, std::string> strpair;

class Player;
class Deck;

enum class GameState
{
    Menu,
    Start,
    Bets,
    FirstHit,
    PlayerTurn,
    DealerTurn,
    Exit
};

class GameMode : public Singleton <GameMode>
{
    friend class Singleton<GameMode>;

private:
    ~GameMode();

    GameState gameState = GameState::Menu;

    Player* player;
    Player* dealer;
    Deck* deck;

    int bank;

public:
    
    GameState GetGameState() const { return gameState; }
    void SetGameState(GameState state) { gameState = state; }

    Player& GetPlayer() const { return *player;  }

    int GetBank() { return bank; }
    void SetBank(int value) { bank = value; }

    void Welcome();
    void ShowMenu();
    void StartGame();
    void StartBets();
    void StartDealerTurn();
    void ShowStat(strpair name, strpair money, strpair score);
    void ContinueGame();
    void ExitGame();
    void ConfirmExit();
    void CancelExit();
    void ShowRules();
    void ShowGUI();

    void PlaceBet(const int& amount);

    void Hit();

    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();

private:
    void CheckScore();
    void GameOver(const Player& winner);
};

