#include <iostream>
#include <string>
#ifndef Card_H
#define Card_H

class Card
{
    public:
        Card(int, int);
        Card();
        int getSuitValue() const;
        std::string getSuitName() const;
        int getValue() const;
        void printCard() const;
        void discardCard();
        std::string getName() const;
        bool checkStatus() const;
    
    private:
        int value;
        int suit;
        bool discarded;
        static const int CLUBS = 1;
        static const int DIAMONDS = 2;
        static const int HEARTS = 3;
        static const int SPADES = 4;
};

#endif
