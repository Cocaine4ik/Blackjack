#include "GameMode.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"

GameMode::~GameMode()
{
    delete player;
    delete dealer;
    delete deck;
}

void GameMode::StartGame()
{
    deck = new Deck();
    deck->Shuffle();

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    player = new Player(name);
    dealer = new Player("Dealer");
}