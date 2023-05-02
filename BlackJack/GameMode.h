#pragma once
#include "Singleton.h"

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

    void StartGame();
    void StartBets();

    void PlaceBet(const int& amount);

    void Hit();
    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();

    void Pause();
    void Exit();

private:
    void CheckScore();
    void GameOver(const Player& winner);
};

