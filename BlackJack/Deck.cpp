#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <deque>
#include <queue>
#include <iterator>
#include <random>


Deck::Deck()
{
    for (int i = static_cast<int>(Suit::Clubs);
        i <= static_cast<int>(Suit::Spades);
        i++) 
    {
        for(int k = static_cast<int>(Rank::Ace);
            k <= static_cast<int>(Rank::King);
            k++) 
        {
            Card card(static_cast<Suit>(i), static_cast<Rank>(k));
            
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