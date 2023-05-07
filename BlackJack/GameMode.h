#pragma once
#include "Singleton.h"
#include <utility>
#include <string>

typedef std::pair<std::string, std::string> strpair;

class Player;
class Deck;

/**
 * @brief Game states enum class
*/
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

/**
 * @brief Game Mode class
 * manage gameplay
 * based on Singleton
*/
class GameMode : public Singleton <GameMode>
{
    friend class Singleton<GameMode>;

private:
    /**
     * @brief Default constructor
    */
    GameMode();

    /*
    * @brief Default destructor
    */
    ~GameMode();

    /**
     * @brief Game state, default in Menu
    */
    GameState gameState = GameState::Menu;

    /**
     * @brief Pointer to the player
    */
    Player* player;

    /**
     * @brief Pointer to the dealer
    */
    Player* dealer;

    /**
     * @brief Pointer to the deck
    */
    Deck* deck;

    /**
     * @brief Current bank
    */
    int bank;

public:
    
    /**
     * @brief Getter and setter for GameState
    */
    GameState GetGameState() const { return gameState; }
    void SetGameState(GameState state) { gameState = state; }

    /**
     * @brief Get player
     * @return &Player 
    */
    Player& GetPlayer() const { return *player;  }

    /**
     * @brief Getter and setter for the Bank
    */
    int GetBank() const { return bank; }
    void SetBank(int value) { bank = value; }

    /**
     * @brief Show Welcome message
     * then show Menu
    */
    void Welcome();

    /**
     * @brief Show Menu
    */
    void ShowMenu();

    /**
     * @brief Start game
     * Ask player to prompt his name
     * Create abd shuffle deck
     * Initiate Bets round
    */
    void StartGame();

    /**
     * @brief Start Best round
    */
    void StartBets();

    /**
     * @brief Star Dealer Turn
     * when player have already standed
    */
    void StartDealerTurn();

    /**
     * @brief Show player stat to console
     * @param name strpair, first - name label, second - name value
     * @param money strpair, first - money label, second - money value
     * @param score strpair, first - score label, second - score value
    */
    void ShowStat(strpair name, strpair money, strpair score);

    /**
     * @brief If it possible continue game
     * abd start next round
    */
    void ContinueGame();

    /**
     * @brief Exit the game
    */
    void ExitGame();

    /**
     * @brief Show game rules from file Rules.txt
     * then show Menu
    */
    void ShowRules();

    /**
     * @brief Show game user interface
    */
    void ShowGUI();

    /**
     * @brief Place bet
     * Then Hit
     * @param amount &int
    */
    void PlaceBet(const int& amount);

    /**
     * @brief Take the card or cards in first round
     * show cards and players stats
     * check score
    */
    void Hit();

    /**
     * @brief Stop take cards
     * give turn to the dealer
    */
    void Stand();

    /**
     * @brief Take 1 card, x2 current bet and stand
    */
    void DoubleDown();

    /**
     * @brief Surrender, end the game, return half of your bet
    */
    void Surrender();

private:

    /**
     * @brief Check score
     * if the score is enought for end the game - call GameOver() function
    */
    void CheckScore();

    /**
     * @brief End the game, notify winner
     * add money to the winner and show Menu
     * @param winner 
    */
    void GameOver(const Player& winner);
};

