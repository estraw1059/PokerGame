#include "Dealer.h"

using namespace std;

Dealer::Dealer(Deck &deck)
{
    this->deck = &deck;
}

deque<Card> Dealer::dealHand()
{
    deque<Card> hand;
    for (int i = 0; i < handSize; i++)
    {
        hand.push_front(this->deck->dealTopCard());
    };
    return hand;

}

