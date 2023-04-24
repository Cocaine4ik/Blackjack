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

public:
    GameState GetGameState() const { return gameState; }
    void SetGameState(GameState state) { gameState = state; }

    Player& GetPlayer() const { return *player;  }

    void StartGame();
};

