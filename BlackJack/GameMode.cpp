#include "GameMode.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
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
    if (gameState != GameState::Menu) return;

    SetGameState(GameState::Start);

    system("cls");

    deck = new Deck();
    deck->Shuffle();

    InputHandler::GetInstance().Block(true);

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    InputHandler::GetInstance().Block(false);

    player = new Player(name);
    dealer = new Player("Dealer", true);

    StartBets();
}

void GameMode::StartBets()
{
    SetGameState(GameState::Bets);

    system("cls");

    auto& uiController = UIController::GetInstance();

    uiController.ShowPlayerStat(player->GetName(), player->GetMoney(), player->GetScore());
    uiController.ShowBets();

}

void GameMode::Hit()
{
    system("cls");
    auto& uiController = UIController::GetInstance();

    // Dealer
    if (GetGameState() == GameState::FirstHit)
    {
        dealer->Hit(*deck);
        dealer->Hit(*deck);
    }

    // Player
    if (GetGameState() == GameState::FirstHit)
    {
        player->Hit(*deck);
        player->Hit(*deck);
    }
    else
    {
        if (GetGameState() == GameState::PlayerTurn) player->Hit(*deck);
        else if (GetGameState() == GameState::DealerTurn) dealer->Hit(*deck);
    }

    uiController.ShowPlayerStat(dealer->GetName(), dealer->GetMoney(), dealer->GetScore(), dealer->IsDealer());
    dealer->ShowCards();

    uiController.ShowPlayerStat(player->GetName(), player->GetMoney(), player->GetScore());
    player->ShowCards();
    
    if (GetGameState() == GameState::DealerTurn) uiController.ShowDealerUI();
    else uiController.ShowGUI();

    CheckScore();

    if (GetGameState() != GameState::DealerTurn && GetGameState() != GameState::Menu)
    {
        SetGameState(GameState::PlayerTurn);
    }

}

void GameMode::Stand()
{
    if (GetGameState() != GameState::PlayerTurn) return;

    player->Stand();

    dealer->GetFirstCard().FaceUp();

    system("cls");

    auto& uiController = UIController::GetInstance();

    uiController.ShowPlayerStat(dealer->GetName(), dealer->GetMoney(), dealer->GetScore(), dealer->IsDealer());
    dealer->ShowCards();

    uiController.ShowPlayerStat(player->GetName(), player->GetMoney(), player->GetScore());
    player->ShowCards();

    SetGameState(GameState::DealerTurn);

    while (GetGameState() != GameState::Menu)
    {
        std::chrono::seconds duration(1);
        std::this_thread::sleep_for(duration);

        Hit();

        if (dealer->GetScore() > player->GetScore()) dealer->Stand();

        CheckScore();
    }
}

void GameMode::DoubleDown()
{
    if (GetGameState() == GameState::FirstHit) return;
    auto bet = player->Bet(bank);
    if (bet == 0) return;
    SetBank(bet);
    Hit();
}

void GameMode::Split()
{
}

void GameMode::Surrender()
{
}

void GameMode::CheckScore()
{
    if (GetGameState() == GameState::Menu) return;

    if (player->GetScore() == 21)
    {
        GameOver(*player);
    }

    else if (dealer->GetScore() == 21)
    {
        GameOver(*dealer);
    }

    else if (player->GetScore() > 21)
    {
        GameOver(*dealer);
    }

    else if (dealer->GetScore() > 21)
    {
        GameOver(*player);
    }

    else if(player->IsStand() && dealer->IsStand())
    {
        GameOver(player->GetScore() > dealer->GetScore() ? *player : *dealer);
    }
}

void GameMode::GameOver(const Player& winner)
{
    std::cout << winner.GetName() << " WIN!!! " << std::endl;

    UIController::GetInstance().ShowMenu();
}

void GameMode::PlaceBet(const int& amount)
{
    if (gameState != GameState::Bets) return;
    
    auto bet = player->Bet(amount);
    SetBank(bet);
    SetGameState(GameState::FirstHit);
    Hit();
}

