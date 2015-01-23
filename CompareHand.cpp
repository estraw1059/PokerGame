#include "CompareHand.h"

using namespace std;

CompareHand::CompareHand(deque<Card> hand)
{
    this->hand = hand;
}

int CompareHand::determineValue()
{
    if (checkForFlush())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CompareHand::checkForStraightFlush()
{
    if (checkForFlush() && checkForStraight())
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

bool CompareHand::checkForFourOfAKind()
{
    Card current(0,0);
    current = LookForMatches(4, 0);
    if (current.getValue() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CompareHand::checkForFullHouse()
{
    Card current(0,0);
    current = LookForMatches(3, 0);
    if (current.getValue() != 0)
    {
        int valueToSkip = current.getValue();
        current = LookForMatches(2, current.getValue());
        if (current.getValue() != 0)
        {
            return 1;
        }
    }
    
    return 0;
}

bool CompareHand::checkForFlush()
{
    int amountInSuit = 0;
    for (int y = 0; y < Suit::AMOUNTOFSUITES; y++)
    {
        for (int x = 0; x < this->hand.size(); x++)
        {
            if (this->hand[x].getSuitValue() == y)
            {
                amountInSuit = amountInSuit + 1;
                
                if (amountInSuit == AMOUNTFORFLUSH)
                {
                    return 1;
                }
                else
                {
                    continue;
                }
            }
            
            else
            {
                continue;
            }
        }
        amountInSuit = 0;
    }
    
    return 0;
}
              

bool CompareHand::checkForStraight()
{
    deque<Card> handCheck = sortCard(this->hand);
    int amountInARow = 0;
    for (int x = 0; x < (handCheck.size() - 1); x++)
    {
        Card first = handCheck[x];
        Card second = handCheck[x+1];
        if (first.getValue() == ( second.getValue() + 1) )
        {
            amountInARow = amountInARow + 1;
            if (amountInARow == this->LENGTHOFSTRAIGHT)
            {
                return 1;
            }
            
            else
            {
                continue;
            }
        }
        
        else
        {
            amountInARow = 0;
        }
    }  
    return 0;
}

bool CompareHand::checkForThreeOfAKind()
{
    Card current(0,0);
    current = LookForMatches(3, 0);
    if (current.getValue() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool CompareHand::checkForTwoPair()
{
    int avoid;
    Card current(0,0);
    current = LookForMatches(2, 0);
    if (current.getValue() != 0)
    {
        avoid = current.getValue();
        current = LookForMatches(2, avoid);
        if (current.getValue() != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool CompareHand::checkForPair()
{
    Card current(0,0);
    current = LookForMatches(2, 0);
    if (current.getValue() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int CompareHand::highCardValue()        //Just need to write this and the class is done.
{
    
} 

Card CompareHand::LookForMatches(int amountOfMatches, int valueToSkip)        //Finds if the hand contains a certain amount of matches
{
    int amountOfMatchesFound;
    for (int i = 0; i < this->hand.size(); i++)
    {
        amountOfMatchesFound = 0;
        Card current = hand[i];  
        if (current.getValue() == valueToSkip)
        {
            continue;
        }
        for (int g = 0; g < this->hand.size(); g++)
        {
            Card comparer = hand[g];
            if (current.getValue() == comparer.getValue())
            {
                amountOfMatchesFound++;
                if (amountOfMatchesFound == amountOfMatches)
                {
                    return current;
                }
            }
        }
    }
    
    Card Nothing(0, 0);
    return Nothing;
}

deque<Card> CompareHand::sortCard(deque<Card> hand)
{
    int highestValue = 0;
    int indexOfSpot = 0;
    deque<Card> sortedList;
    int amount = hand.size();
    for (int y = 0; y < amount; y++)
    {
        
        for (int x = 0; x < hand.size(); x++)
        {
            if (hand[x].getValue() > highestValue)
            {
                highestValue = hand[x].getValue();
                indexOfSpot = x;
            }   
        }
        
        sortedList.push_back(hand[indexOfSpot]);
        Card current(0,0);
        hand[indexOfSpot] = current;
        highestValue = 0;
    
    }
    
    return sortedList;
            
            
}  
    
