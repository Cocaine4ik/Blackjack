#include "Player.h"
#include <string>
#include "Deck.h"

#define DEFAULT_MONEY_VALUE 1000

Player::Player(std::string name)
{
    this->name = name;
    this->money = DEFAULT_MONEY_VALUE;
    this->score = 0;
}

void Player::TakeCard(Deck& deck)
{
    auto card = deck.DealCard();
    mainHand.push_front(card);
}
