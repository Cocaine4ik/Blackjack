#pragma once
#include <string>
#include <list>
#include "Card.h"

class Deck;

class Player
{
private:
    std::string name;
    int money;
    int score;
    
    bool isDealer;
    bool isStand;

    std::list<Card> mainHand;

public:
    Player(std::string name, bool isDealer = false);
    
    std::string GetName() const { return name; }
    int GetMoney() const { return money; }
    int GetScore() const { return score; }

    void AddMoney(int value) { money += value; }
    void SetScore(int value) { score = value; }

    bool IsDealer() { return isDealer; }
    bool IsStand() { return isStand; }

    void ShowCards();
    void ClearHands();

    int Bet(int value);
    void Hit(Deck& deck);
    void Stand() { isStand = true; }

    Card& GetFirstCard() { return mainHand.front(); }
    int GetCardsCount() const { return mainHand.size(); }

private:
    void CalculateScore();

};


