#ifndef CompareHand_H
#define CompareHand_H
#include <deque>
#include <iostream>
#include "Card.h"
#include "Suit.h"

class CompareHand
{
   public:
    CompareHand(std::deque<Card>);
    int determineValue();
    bool checkForStraightFlush();
    bool checkForFourOfAKind();
    bool checkForFullHouse();
    bool checkForFlush();
    bool checkForStraight();
    bool checkForThreeOfAKind();
    bool checkForTwoPair();
    bool checkForPair();
    int highCardValue();
    std::deque<Card> sortCard(std::deque<Card>);
   private:
    Card LookForMatches(int, int);
    int handValue;
    int LENGTHOFSTRAIGHT = 5;
    int AMOUNTFORFLUSH = 5;
    std::deque<Card> hand;

};

#endif
