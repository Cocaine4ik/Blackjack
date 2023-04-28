#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <deque>
#include <queue>
#include <iterator>
#include <random>


Deck::Deck()
{
    for (Suit suit : { Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades })
    {
        for (Rank rank : {Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six, Rank::Seven,
        Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King })
        {
            Card card(suit, rank);
            
            cards.push(card);
        }
    }
}

Card Deck::DealCard()
{
    auto card = std::move(cards.front());
    cards.pop();

    return card;
}

void Deck::Shuffle()
{
    std::deque<Card> temp;

    while (!cards.empty()) 
    {
        temp.push_back(cards.front());
        cards.pop();
    }
    
    std::shuffle(temp.begin(), temp.end(), std::mt19937{ std::random_device{}() });

    while (!temp.empty()) 
    {
        cards.push(std::move(temp.front()));
        temp.pop_front();
    }  
}