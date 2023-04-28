#pragma once
#include <vector>
#include <string>

enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum class Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};
class Card
{
private:
    Suit suit;
    Rank rank;
    bool isFaced = false;

    std::vector<std::string> icon;

    void SetIcon();

public:
    Card(Suit suit, Rank rank);

    bool operator == (const Card& other);

    void Show();
    
    Suit GetSuit() { return this->suit; }

    Rank GetRank() { return this->rank; }

    char GetSuitAsChar();
    char GetRankAsChar();



    int GetPoints();
};







