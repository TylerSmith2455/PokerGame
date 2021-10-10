/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Card class.
 * Author: (your name)
 */
#include "card.h"
#include<iomanip>
// Default constructor marks card as invalid
Card::Card() {
    suit = cSuits(0);
    point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    if (this->point < other.point)
        return -1;
    else if (this->point > other.point)
        return 1;
    else 
        return 0;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again   
void Card::print() const
{
    //const char SPADE[] = "\e[0;30;47m\xe2\x99\xa0\e[0;37;40m";
    //const char CLUB[] = "\e[0;30;47m\xe2\x99\xa3\e[0;37;40m";
    //const char HEART[] = "\e[0;31;47m\xe2\x99\xa5\e[0;37;40m";
    //const char DIAMOND[] = "\e[0;31;47m\xe2\x99\xa6\e[0;37;40m";
    switch (suit) {
        case cSuits(1):
            if (point < 11)
                cout << SPADE << setw(2) << point << SPADE;
            else if (point == 11)
                cout << SPADE << setw(2) << "J" << SPADE;
            else if (point == 12)
                cout << SPADE << setw(2) << "Q" << SPADE;
            else if (point == 13)
                cout << SPADE << setw(2) << "K" << SPADE;
            else
                cout << SPADE << setw(2) << "A" << SPADE;
            break;
        case cSuits(2):
            if (point < 11)
                cout << CLUB << setw(2) << point << CLUB;
            else if (point == 11)
                cout << CLUB << setw(2) << "J" << CLUB;
            else if (point == 12)
                cout << CLUB << setw(2) << "Q" << CLUB;
            else if (point == 13)
                cout << CLUB << setw(2) << "K" << CLUB;
            else
                cout << CLUB << setw(2) << "A" << CLUB;
            break;
        case cSuits(3):
            if (point < 11)
                cout << HEART << setw(2) << point << HEART;
            else if (point == 11)
                cout << HEART << setw(2) << "J" << HEART;
            else if (point == 12)
                cout << HEART << setw(2) << "Q" << HEART;
            else if (point == 13)
                cout << HEART << setw(2) << "K" << HEART;
            else
                cout << HEART << setw(2) << "A" << HEART;
            break;
        case cSuits(4):
            if (point < 11)
                cout << DIAMOND << setw(2) << point << DIAMOND;
            else if (point == 11)
                cout << DIAMOND << setw(2) << "J" << DIAMOND;
            else if (point == 12)
                cout << DIAMOND << setw(2) << "Q" << DIAMOND;
            else if (point == 13)
                cout << DIAMOND << setw(2) << "K" << DIAMOND;
            else
                cout << DIAMOND << setw(2) << "A" << DIAMOND;
            break;
    }

}
