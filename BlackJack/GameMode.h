#pragma once
#include "Singleton.h"

class Player;
class Deck;

enum class GameState
{
    Menu,
    Pause,
    Bets,
    Game,
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
};

