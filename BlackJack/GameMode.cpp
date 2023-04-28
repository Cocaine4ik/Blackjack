#include "GameMode.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "InputHandler.h"
#include "UIController.h"

GameMode::~GameMode()
{
    delete player;
    delete dealer;
    delete deck;
}

void GameMode::StartGame()
{
    system("cls");

    SetGameState(GameState::Game);

    deck = new Deck();
    deck->Shuffle();

    InputHandler::GetInstance().Block(true);

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    InputHandler::GetInstance().Block(false);

    player = new Player(name);
    dealer = new Player("Dealer");
}

    StartBets();
}

void GameMode::StartBets()
{
    system("cls");

    auto& uiController = UIController::GetInstance();

    uiController.ShowPlayerStat(player->GetName(), player->GetMoney(), player->GetScore());
    uiController.ShowBets();
    SetGameState(GameState::Bets);
}

void GameMode::StartRound()
{
    system("cls");
    auto& UIController = UIController::GetInstance();
    UIController.ShowPlayerStat(player->GetName(), player->GetMoney(), player->GetScore());
    player->TakeCard(*deck);

}
