#pragma once
#include <vector>
#include <string>

enum class Suit {
    Clubs = 5,
    Diamonds = 4,
    Hearts = 3,
    Spades = 6
};

enum class Rank {
    Ace = 65,
    Two = 50,
    Three = 51,
    Four = 52,
    Five = 53,
    Six = 54,
    Seven = 55,
    Eight = 56,
    Nine = 57,
    Ten = 0,
    Jack = 74,
    Queen = 81,
    King = 75
};

class Card
{
private:

    std::vector<std::string> icon;

    Suit suit;
    Rank rank;
    bool isFaced = false;

public:
    Card(Suit suit, Rank rank);

    bool operator == (const Card& other);
    
    Suit GetSuit() { return this->suit; }
    Rank GetRank() { return this->rank; }

    void SetIcon();

    int GetPoints();

    std::vector<std::string> GetIcon() { if (icon.empty()) SetIcon(); return icon; }
};