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

    std::vector<std::string> frontIcon;
    std::vector<std::string> backIcon;

    Suit suit;
    Rank rank;
    bool isFaced = false;

public:
    Card(Suit suit, Rank rank);

    bool operator == (const Card& other);
    
    Suit GetSuit() { return this->suit; }
    Rank GetRank() { return this->rank; }

    bool IsFaced() { return isFaced; }
    void FaceUp() { isFaced = true; }
    void SetFrontIcon();
    void SetBackIcon();

    int GetPoints();

    std::vector<std::string> GetFrontIcon() { if (frontIcon.empty()) SetFrontIcon(); return frontIcon; }
    std::vector<std::string> GetBackIcon() { if (backIcon.empty()) SetBackIcon(); return backIcon; }
};