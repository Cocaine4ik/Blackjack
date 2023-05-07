#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include "GameConfig.h"

Card::Card(Suit suit, Rank rank)
{
	this->suit = suit;
	this->rank = rank;
}

void Card::SetFrontIcon()
{
	using namespace std::string_literals;

	// if card rank euqal 10 set string - 10, else set character from enum
	auto rank = this->rank == Rank::Ten ? "10" : std::string(1, (static_cast<char>(this->rank)));

	char suit = static_cast<char>(this->suit);

	frontIcon.push_back("---------"s);

	if (rank == "10") frontIcon.push_back("|"s + " "s + rank + suit + "   "s + "|"s);
	else frontIcon.push_back("|"s + " "s + rank + suit + "    "s + "|"s);

	frontIcon.push_back("|"s + "       "s + "|"s);
	frontIcon.push_back("|"s + "   "s + suit + "   "s + "|"s);
	frontIcon.push_back("|"s + "       "s + "|"s);

	if (rank == "10") frontIcon.push_back("|"s + " "s + rank + suit + "   "s + "|"s);
	else frontIcon.push_back("|"s + " "s + rank + suit + "    "s + "|"s);

	frontIcon.push_back("---------"s);

}

void Card::SetBackIcon()
{
	using namespace std::string_literals;

	auto pattern = "#########";

	backIcon.push_back("---------"s);
	backIcon.push_back("|"s + "#######"s + "|"s);
	backIcon.push_back("|"s + "#######"s + "|"s);
	backIcon.push_back("|"s + "#######"s + "|"s);
	backIcon.push_back("|"s + "#######"s + "|"s);
	backIcon.push_back("|"s + "#######"s + "|"s);
	backIcon.push_back("---------"s);
}

int Card::GetPoints()
{
	switch (this->rank)
	{
	case Rank::Ace: return 1;
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