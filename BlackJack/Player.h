#pragma once
#include <string>
#include <list>
#include "Card.h"

class Deck;

/**
 * @brief Player class
*/
class Player
{
private:
    /**
     * @brief Player name as string
    */
    std::string name;

    /**
     * @brief Current moeny
    */
    int money;

    /**
     * @brief Current score - some of card points
    */
    int score;
    
    /**
     * @brief Is current player - Dealer
    */
    bool isDealer;

    /**
     * @brief Is current player stop taking cards and Stand
    */
    bool isStand;

    /**
     * @brief List of card in main hand
    */
    std::list<Card> mainHand;

public:
    /**
     * @brief Constructor
     * @param std::string player name
     * @param bool is player dealer
    */
    Player(std::string name, bool isDealer = false);
    
    /**
     * @brief Get player name
    */
    std::string GetName() const { return name; }

    /**
     * @brief Get and add money to player
    */
    int GetMoney() const { return money; }
    void AddMoney(int value) { money += value; }

    /**
     * @brief Get and set player score
    */
    void SetScore(int value) { score = value; }
    int GetScore() const { return score; }

    /**
     * @brief Get is player Dealer
    */
    bool IsDealer() { return isDealer; }

    /**
     * @brief Get is player Stand
    */
    bool IsStand() { return isStand; }

    /**
     * @brief Show player cards on console
    */
    void ShowCards();

    /**
     * @brief Cleaer player hands
     * prepare to next round
    */
    void ClearHands();

    /**
     * @brief Make a bet
     * @param int
     * @ return int current bet 
    */
    int Bet(int value);

    /**
     * @brief Ask for Card
     * @param Deck&
    */
    void Hit(Deck& deck);

    /**
     * @brief Set isStand to true
    */
    void Stand() { isStand = true; }

    /**
     * @brief Get first card from main hand
     * @return &Card
    */
    Card& GetFirstCard() { return mainHand.front(); }

    /**
     * @brief Get current size of the main hand
     * @return int
    */
    int GetCardsCount() const { return mainHand.size(); }

private:

    /**
     * @brief Recalculate current player cards score
    */
    void CalculateScore();

};


