#include "Deck.h"
using namespace std;

Deck::Deck()
{
    makeDeck();
    shuffleDeck();
}
    
void Deck::makeDeck()
{
    int cardValue;
    for (int suit = 1; suit < 5; suit ++)
    {
        cardValue = 2;
        for (cardValue; cardValue < 15; cardValue++)
        {
            Card currentCard(cardValue, suit);
            deck.push_back(currentCard);
        }
    }
 
        
}
void Deck::shuffleDeck()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle( deck.begin(), deck.end(), default_random_engine(seed) );
}
    
void Deck::printDeck()
{
    for (int counter = 0; counter < deck.size(); counter ++)
    {
        Card currentCard = deck[counter];
        currentCard.printCard();
    }

}

Card Deck::dealTopCard()
{
    Card current = deck.front();
    deck.pop_front();
    return current;
}

