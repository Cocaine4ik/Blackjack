#pragma once
#include <queue>
#include "Card.h"

/**
 * @brief Deck class
 * represents Deck with Cards
*/
class Deck
{
private:
   /**
    * @brief Queue with cards
    * so we can only take card from top
   */
   std::queue<Card> cards;

public:
    /**
     * @brief Default constuctor
    */
    Deck();

    /**
     * @brief Deal card from the deck to the player
     * @return Card
    */
    Card DealCard();

    /**
     * @brief Shuffle the deck
     * use std::shuffle algorithm
    */
    void Shuffle();
};

