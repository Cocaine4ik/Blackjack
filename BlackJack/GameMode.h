#pragma once

class Player;
class Deck;

enum class GameState
{
    Menu,
    Pause,
    Game,
    Exit
};

class GameMode
{

private:
    GameState gameState = GameState::Menu;

    Player* player;
    Player* dealer;
    Deck* deck;


public:
    ~GameMode();
    static GameMode& GetInstance() { static GameMode instance; return instance; }

    GameState GetGameState() { return gameState; }
    void SetGameState(GameState state) { gameState = state; }

    void StartGame();

private:
    GameMode() {};
    GameMode(const GameMode&) = delete;
    GameMode& operator = (const GameMode&) = delete;
};

