#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

void Card::SetIcon()
{
    using namespace std::string_literals;

    auto rank = GetRankAsChar();
    auto suit = GetSuitAsChar();

    icon.push_back("---------"s);
    icon.push_back("|"s + " "s + rank + suit + "    "s + "|"s);
    icon.push_back("|"s + "       "s + "|"s);
    icon.push_back("|"s + "   "s + suit + "   "s + "|"s);
    icon.push_back("|"s + "       "s + "|"s);
    icon.push_back("|"s + "    "s + rank + suit + " "s + "|"s);
    icon.push_back("---------"s);
}

Card::Card(Suit suit, Rank rank)
{
	this->suit = suit;
	this->rank = rank;

}

void Card::Show()
{
    if (icon.empty()) SetIcon();
    
    for (auto str : icon) 
    {
        std::cout << str << std::endl;
    }
}

char Card::GetSuitAsChar()
{
    switch (this->suit)
    {
    case Suit::Clubs: return 5; break;
    case Suit::Diamonds: return 4; break;
    case Suit::Hearts: return 3; break;
    case Suit::Spades: return 6; break;
    default: return 0; break;
    }
}

char Card::GetRankAsChar()
{
    switch (this->rank)
    {
    case Rank::Ace: return 'A';
    case Rank::Two: return '2';
    case Rank::Three: return '3';
    case Rank::Four: return '4';
    case Rank::Five: return '5';
    case Rank::Six: return '6';
    case Rank::Seven: return '7';
    case Rank::Eight: return '8';
    case Rank::Nine: return '9';
    case Rank::Ten: return '10';
    case Rank::Jack: return 'J';
    case Rank::Queen: return 'Q';
    case Rank::King: return 'K';
    default: return 0;
    }
}

int Card::GetPoints()
{
	switch (this->rank)
	{
	case Rank::Ace: return 11;
	case Rank::Two: return 2;
	case Rank::Three: return 3;
	case Rank::Four: return 4;
	case Rank::Five: return 5;
	case Rank::Six: return 6;
	case Rank::Seven: return 7;
	case Rank::Eight: return 8;
	case Rank::Nine: return 9;
	case Rank::Ten:
	case Rank::Jack:
	case Rank::Queen:
	case Rank::King:
		return 10;
	default: return 0;
	}
}

bool Card::operator==(const Card& other)
{
	return this->suit == other.suit && this->rank == other.rank ? true : false;
}
