#pragma once
#include <queue>
#include "Card.h"


class Deck
{
private:
   std::queue<Card> cards;

public:
    Deck();

    /**
     * @brief 
     * @return 
    */
    Card DealCard();

    /**
     * @brief 
    */
    void Shuffle();
};

