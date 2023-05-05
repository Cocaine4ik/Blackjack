#include "GameMode.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include "Player.h"
#include "Deck.h"
#include "InputHandler.h"

#define RULES_PATH "rules.txt"
#define STAT_BORDER_WIDTH 72

GameMode::~GameMode()
{
    delete player;
    delete dealer;
    delete deck;
}

void GameMode::Welcome()
{
    std::cout << "Welcome to Black Jack Console Game" << std::endl << std::endl;

    std::cout << "MENU:\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
}

void GameMode::ShowMenu()
{
    SetGameState(GameState::Menu);

    std::cout << "MENU:\t" << "SPACE - Continue\t" << "1 - New Game\t" << "2 - Rules\t" << "3 - Exit" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
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


    ShowStat(
        strpair("Name: ", player->GetName()),
        strpair("Money: ", std::to_string(player->GetMoney())), 
        strpair("Score: ", std::to_string(player->GetScore()))
    );
        using namespace std::string_literals;

        auto& config = GameConfig::GetInstance();

        std::string str = "Make your bet:\tZ - "s + std::to_string(config.GetMinBet())
            + "$\tX - "s + std::to_string(config.GetMediumBet())
            + "$\tC - "s + std::to_string(config.GetLargeBet())
            + "$\tV - "s + std::to_string(config.GetMaxBet()) + "$"s;

        std::cout << str;
}

void GameMode::ShowStat(strpair name, strpair money, strpair score)
{
    std::string border(STAT_BORDER_WIDTH, '*');
    std::string stat(STAT_BORDER_WIDTH, ' ');

    stat.replace(0, 2, "* ");
    stat.replace(2, name.first.length() + name.second.length(), name.first + name.second);
    stat.replace(STAT_BORDER_WIDTH / 3, money.first.length() + money.second.length(), money.first + money.second);
    stat.replace(STAT_BORDER_WIDTH / 3 * 2, score.first.length() + score.second.length(), score.first + score.second);
    stat.replace(stat.length() - 1, 1, "*");

    std::cout << std::endl;
    std::cout << border << std::endl;
    std::cout << stat << std::endl;
    std::cout << border << std::endl;
    std::cout << std::endl;
}

void GameMode::Hit()
{
    system("cls");

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

    ShowStat(
        strpair("Name: ", dealer->GetName()),
        strpair("Bank: ", std::to_string(GetBank())),
        strpair("Score: ", std::to_string(dealer->GetScore()))
    );
    dealer->ShowCards();

    ShowStat(
        strpair("Name: ", player->GetName()),
        strpair("Money: ", std::to_string(player->GetMoney())),
        strpair("Score: ", std::to_string(player->GetScore()))
    );
    player->ShowCards();
    
    if (GetGameState() == GameState::DealerTurn)
    {
        std::cout << std::endl;
        std::cout << "...DEALER TURN..." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        ShowGUI();
    }

    CheckScore();

    if (GetGameState() != GameState::DealerTurn && GetGameState() != GameState::Menu)
    {
        SetGameState(GameState::PlayerTurn);
    }
}

void GameMode::StartDealerTurn()
{
    system("cls");

    dealer->GetFirstCard().FaceUp();

    ShowStat(
        strpair("Name: ", dealer->GetName()),
        strpair("Bank: ", std::to_string(GetBank())),
        strpair("Score: ", std::to_string(dealer->GetScore()))
    );
    dealer->ShowCards();

    ShowStat(
        strpair("Name: ", player->GetName()),
        strpair("Money: ", std::to_string(player->GetMoney())),
        strpair("Score: ", std::to_string(player->GetScore()))
    );
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

void GameMode::Stand()
{
    if (GetGameState() != GameState::PlayerTurn) return;

    player->Stand();

    StartDealerTurn();
}

void GameMode::DoubleDown()
{
    if (GetGameState() == GameState::FirstHit) return;
    auto bet = player->Bet(bank);
    if (bet == 0) return;
    SetBank(bet);
    Hit();
    Stand();
}

void GameMode::Split()
{
}

void GameMode::Surrender()
{
}

void GameMode::ContinueGame()
{
    bank = 0;
    player->ClearHands();
    dealer->ClearHands();

    delete deck;
    deck = new Deck();
    deck->Shuffle();
    StartBets();
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
    system("cls");
    ShowStat(
        strpair("Name: ", dealer->GetName()),
        strpair("Bank: ", std::to_string(GetBank())),
        strpair("Score: ", std::to_string(dealer->GetScore()))
    );
    dealer->ShowCards();

    ShowStat(
        strpair("Name: ", player->GetName()),
        strpair("Money: ", std::to_string(player->GetMoney())),
        strpair("Score: ", std::to_string(player->GetScore()))
    );
    player->ShowCards();

    ShowStat(
        strpair(" ", ""),
        strpair(winner.GetName(), " WIN!"),
        strpair(" ", "")
    );

    if (winner.GetName() == player->GetName()) player->AddMoney(bank*2);

    ShowMenu();
}

void GameMode::ExitGame()
{
}

void GameMode::ConfirmExit()
{
}

void GameMode::CancelExit()
{
}

void GameMode::ShowRules()
{
    system("cls");
    std::ifstream fin(RULES_PATH);

    if (!fin.is_open())
    {
        throw std::runtime_error("Error opening file;");
    }

    try
    {
        char ch;
        while (fin.get(ch))
        {
            std::cout << ch;
        }
    }

    catch (const std::exception& ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    fin.close();

    std::cout << std::endl;
}

void GameMode::ShowGUI()
{
    std::cout << std::endl;
    std::cout << "GAME MENU:\t" << "Q - Hit\t\t" << "W - Stand\t" << "E - Double Down\t\t" << "R - Surrender" << std::endl;
    std::cout << "Choose option to continue..." << std::endl;
    std::cout << std::endl;
}

void GameMode::PlaceBet(const int& amount)
{
    if (gameState != GameState::Bets) return;
    
    auto bet = player->Bet(amount);
    SetBank(bet);
    SetGameState(GameState::FirstHit);
    Hit();
}

