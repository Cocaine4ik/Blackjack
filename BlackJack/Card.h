#pragma once

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

public:
    Card(Suit suit, Rank rank);

    bool operator == (const Card& other);

    void Show();
    
    Suit GetSuit() { return this->suit; }

    Rank GetRank() { return this->rank; }

    int GetPoints();
};







