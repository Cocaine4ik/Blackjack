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
    
    std::list<Card> mainHand;
    std::list<Card> splitHand;
public:
    Player(std::string name);
    
    std::string GetName() { return name; }
    int GetMoney() { return money; }
    int GetScore() { return score; }

    void SetMoney(int value) { money = value; }
    void SetScore(int value) { score = value; }

    void TakeCard(Deck& deck);
    void ShowCards();

    int Bet(int value);
    void Hit();
    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();
};


