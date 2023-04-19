#include "Player.h"
#include <string>

#define DEFAULT_MONEY_VALUE 1000

Player::Player(std::string name)
{
    this->name = name;
    this->money = DEFAULT_MONEY_VALUE;
    this->score = 0;
}
