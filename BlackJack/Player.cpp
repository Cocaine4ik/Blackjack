#include "Player.h"
#include <string>
#include "Deck.h"
#include "GameConfig.h"
#include "Card.h"
#include <iostream>

Player::Player(std::string name, bool isDealer)
{
    this->name = name;
    this->money = GameConfig::GetInstance().GetMoney();
    this->score = 0;
    this->isDealer = isDealer;
    this->isStand = false;
    this->canDoubleDown = true;
    this->canSplit = false;
}

void Player::Hit(Deck& deck)
{
    auto card = deck.DealCard();

    if (name != "Dealer") card.FaceUp();

    if (name == "Dealer" && mainHand.size() > 0)
    {
        card.FaceUp();
    }

    mainHand.push_back(card);

    CalculateScore();
}

void Player::ShowCards()
{
    if (mainHand.empty()) return;

    const auto linesCount = mainHand.front().GetFrontIcon().size();

    for (int i = 0; i < linesCount; i++) 
    {
        for (auto& card : mainHand) 
        {
            std::string line;

            if (card.IsFaced()) 
            {
                line = card.GetFrontIcon()[i];
            }
            else
            {
                line = card.GetBackIcon()[i];
            }

            std::cout << line << "\t";
        }

        std::cout << std::endl;
    }
}

int Player::Bet(int value)
{
    if (money < value) return 0;

    money -= value;
    return value;
}

void Player::CalculateScore()
{
    score = 0;
    bool haveAce = false;

    for (auto& card : mainHand)
    {
        if (card.IsFaced())
        {
            score += card.GetPoints();

            if (card.GetRank() == Rank::Ace) haveAce = true;
        }
    }

    if (haveAce && score + 10 <= 21)
    {
        score += 10;
    }
}
