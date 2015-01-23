#include<iostream>
#include<deque>
#include "Deck.h"
#include "Card.h"
#include "Suit.h"
#include "CompareHand.h"
#include "Dealer.h"
using namespace std;

void printHand(deque<Card> hand)
{
    for (int x = 0; x < hand.size(); x++)
    {
        hand[x].printCard();
    }
}

int main()
{
    Deck a;
    Dealer Eric(a);
    deque<Card> myHand;
    myHand = Eric.dealHand();
    CompareHand checker(myHand);
    //myHand = checker.sortCard(myHand);
    //printHand(myHand);
    cout << checker.determineValue(); 
}
