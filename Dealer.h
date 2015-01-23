#ifndef Dealer_H
#define Dealer_H
#include <deque>
#include <iostream>
#include "Deck.h"
#include "Card.h"

class Dealer
{
    public:
        Dealer(Deck &);
        std::deque<Card> dealHand();
    private:
        Deck *deck;
        int handSize = 7;
};

#endif

    
    
