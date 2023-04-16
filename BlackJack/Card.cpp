#include "Card.h"

Card::Card(Suit suit, Rank rank)
{
	this->suit = suit;
	this->rank = rank;
}

void Card::Show()
{
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
