#include "Player.h"
#include <string>
#include "Deck.h"
#include "GameConfig.h"
#include "Card.h"
#include <iostream>

Player::Player(std::string name)
{
    this->name = name;
    this->money = GameConfig::GetInstance().GetMoney();
    this->score = 0;
}

void Player::TakeCard(Deck& deck)
{
    auto card = deck.DealCard();
    mainHand.push_back(card);
}

void Player::ShowCards()
{
    if (mainHand.empty()) return;

    const auto linesCount = mainHand.front().GetIcon().size();

    for (int i = 0; i < linesCount; i++) 
    {
        for (auto& card : mainHand) 
        {
            const auto line = card.GetIcon()[i];

            std::cout << line << "\t";
        }

        std::cout << std::endl;
    }
}

int Player::Bet(int value)
{
    money -= value;
    return value;
}
