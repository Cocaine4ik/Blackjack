#pragma once
#include <string>
#include <unordered_set>

class Card;
class Player
{
private:
    std::string name;
    int money;
    int score;

    std::unordered_set<Card> mainHand;
    std::unordered_set<Card> splitHand;

public:
    void Hit();
    void Stand();
    void DoubleDown();
    void Split();
    void Surrender();
    void Bet();
};


