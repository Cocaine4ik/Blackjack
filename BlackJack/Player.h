#pragma once
#include <string>
#include <list>
#include "Card.h"

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

    void Hit();
    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();
    void Bet();
};


