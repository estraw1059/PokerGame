#include "Card.h"
using namespace std;

Card::Card(int value, int suit)
{
    this->value = value;
    this->suit = suit;
    discarded = false;

}

Card::Card()
{
    this->value = 1;
    this->suit = 1;
}


int Card::getSuitValue() const
{
    return suit;
}


string Card::getSuitName() const
{
    if (suit == this->CLUBS)
    {
        return "Clubs";
    }
    
    if (suit == this->SPADES)
    {
        return "Spades";
    }
    
    if (suit == this->HEARTS)
    {
        return "Hearts";
    }
    
    if (suit == this->DIAMONDS)
    {
        return "Diamonds";
    }
    else
    {
        return "Error";
    }
}
       
string Card::getName() const
{
    if (value > 10)
    {
        if (value == 11)
        {
            return "Jack";
        }
        
        else if (value == 12)
        {
            return "Queen";
        }
        else if (value == 13)
        {
            return "King";
        }
        else if (value == 14)
        {
            return "Ace";
        }
        else
        {
            return "Error";
        }
    }
        
    //Until to_string works
    else if (value == 9)
    {
        return "9";
    }
    else if (value == 8)
    {
        return "8";
    }
    else if (value == 10)
    {
        return "10";
    }
    else if (value == 7)
    {
        return "7";
    }
    else if (value == 6)
    {
        return "6";
    }
    else if (value == 5)
    {
        return "5";
    }
    else if (value == 4)
    {
        return "4";
    }
    else if (value == 3)
    {
        return "3";
    }
    else if (value == 2)
    {
        return "2";
    }  
    else
        return "Error";
}

int Card::getValue() const
{
    return value;
}  
    
void Card::printCard () const
{
    string card;
    card = getName() + " of " + getSuitName();
    cout << card << endl;
}
    
void Card::discardCard()
{
    discarded = true;
}
    
bool Card::checkStatus() const
{
    return discarded;
}
    



