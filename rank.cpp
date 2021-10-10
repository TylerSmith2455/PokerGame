/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iomanip>
#include <sstream>
#include <iostream>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks(0);
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{
    if (point < 2 || point > 14){
        cout << "Invalid card value!" << endl;
    }

    string face;
    if (point > 10){
        switch (point) {
        case 11:
            face = "J";
            break;
        case 12:
            face = "Q";
            break;
        case 13:
            face = "K";
            break;
        case 14:
            face = "A";
            break;
        default:
            face = "Invalid";
            break;
    }
}
else {
    stringstream ss;
    ss << point;
    ss >> face;
}
switch (kind) {
    case hRanks::HighCard:
        cout << RANK_NAMES[1] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::Pair:
        cout << RANK_NAMES[2] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::ThreeOfAKind:
        cout << RANK_NAMES[3] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::Straight:
        cout << RANK_NAMES[4] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::Flush:
        cout << RANK_NAMES[5] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::FullHouse:
        cout << RANK_NAMES[6] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::FourOfAKind:
        cout << RANK_NAMES[7] << " (" << setw(2) << face << ")" << endl;
        break;
    case hRanks::StraightFlush:
        cout << RANK_NAMES[8] << " (" << setw(2) << face << ")" << endl;
        break;
}
}
