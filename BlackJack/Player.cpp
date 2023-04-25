#include "Player.h"
#include <string>
#include "Deck.h"
#include "GameConfig.h"

Player::Player(std::string name)
{
    this->name = name;
    this->money = GameConfig::GetInstance().GetMoney();
    this->score = 0;
}

void Player::TakeCard(Deck& deck)
{
    auto card = deck.DealCard();
    mainHand.push_front(card);
}

int Player::Bet(int value)
{
    money -= value;
    return value;
}
