#include <iostream>
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"

#ifndef Deck_H
#define Deck_H

class Deck
{
    public:
        Deck();
        void makeDeck();
        void shuffleDeck();
        void printDeck();
        Card dealTopCard();


    private:
        std::deque<Card> deck;

};

#endif
