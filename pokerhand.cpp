/* File: pokerhand.cpp
 * Course: CS216 - 001
 * Project: Lab 10 (as part of Project 2)
 * Purpose: the implementation of member functions for the Poker hand class.
 * Author: Tyler Smith
 */
#include "pokerhand.h"
#include <iomanip>

// Default constructor for the poker hand
PokerHand::PokerHand(){
    hand_rank.kind = Rank::hRanks::NoRank;
    hand_rank.point = 0;
}

// Sorts the pokerhand from highest to lowest based on their point value
void PokerHand::sort(){
    Card temp;   // temp card object to be able to switch cards
    for (int i = 0; i < HANDS-1; i++){
        for (int j = i+1; j < HANDS; j++){
            if (cards[i].point < cards[j].point){
                temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

// Determines if every card in the pokerand belongs to the same suit
bool PokerHand::isAllOneSuit() const{
    if ((cards[0].suit == cards[1].suit) && (cards[1].suit == cards[2].suit) && (cards[2].suit == cards[3].suit) && (cards[3].suit == cards[4].suit))
        return true; // returns true if every card is the same suit
    
    else
        return false; // returns false if every card is not the same suit
}

// Determines if the pokerhand cards are a continuous sequence 
bool PokerHand::isSequence() const{
    if ((cards[0].point == cards[1].point + 1) && (cards[1].point == cards[2].point + 1) && (cards[2].point == cards[3].point + 1) && (cards[3].point == cards[4].point + 1)){
        return true; // returns true if they are a sequence
    }
    else
        return false; // returns false if they aren't a sequence
}

// Checks to see if the pokerhand is a straight flush
bool PokerHand::isStraightFlush(){
    sort(); // First sort the deck in order
    if ((isSequence() == true) && (isAllOneSuit() == true)){ // Determine if the hand is both a sequence and the same suit
        hand_rank.kind = Rank::hRanks::StraightFlush;
        hand_rank.point = cards[0].point;
        return true;
    }
    else
        return false;
}

// Check to see if the the pokerhand is a four of a kind
bool PokerHand::isFourOfAKind(){
    sort(); // Sort the poker hand in order
    int same = 1;
    int num;
    // Since the cards are in order check to see if the first four cards are equal
    if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point) && (cards[2].point == cards[3].point)){
                same++;
                num = cards[0].point;
            }
    // Also check to see if the last four cards are equal
    if ((cards[4].point == cards[3].point) && (cards[3].point == cards[2].point) && (cards[2].point == cards[1].point)){
                same++;
                num = cards[4].point;
            }
    if (same == 2){
        hand_rank.kind = Rank::hRanks::FourOfAKind;
        hand_rank.point = num;
        return true;
    }
    else return false;
}

// Check to see if pokerhand is a three of a kind
bool PokerHand::isThreeOfAKind(){
     sort(); // Sort the hand
     int num;
     int same = 1;
     // Check to see if the first three cards are equal
     if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point)){
         same++;
         num = cards[0].point;
     }
     // Check to see if the cards in position 2,3 and 4 cards are equal
     if ((cards[1].point == cards[2].point) && (cards[2].point == cards[3].point)){
         same++;
         num = cards[1].point;
     }
     // Check to see if the last three cards are equal
     if ((cards[2].point == cards[3].point) && (cards[3].point == cards[4].point)){
         same++;
         num = cards[2].point;
     }
      if (same == 2){
          hand_rank.kind = Rank::hRanks::ThreeOfAKind;
          hand_rank.point = num;
          return true;
     }
      else
          return false;
}

// Check to see if the pokerhand is a full house: a pair and a three of a kind
bool PokerHand::isFullHouse() {
    sort(); // Sort the hand
    // check to see if the first three cards are equal and if the last two cards are equal
    if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point) && (cards[3].point == cards[4].point)){
                hand_rank.kind = Rank::hRanks::FullHouse;
                hand_rank.point = cards[0].point;
                return true;
            }
    // check to see if the firsts two cards are equal and the last three cards are equal
    else if ((cards[0].point == cards[1].point) && (cards[2].point == cards[3].point) && (cards[3].point == cards[4].point)){
                hand_rank.kind = Rank::hRanks::FullHouse;
                hand_rank.point = cards[4].point;
                return true;
            }
    else 
        return false;
}

// Check to see if the pokerhand is a flush
bool PokerHand::isFlush(){
    sort(); // sort the hand
    // Check to see if the cards belong to the same suit
    if (isAllOneSuit() == true){
        hand_rank.kind = Rank::hRanks::Flush;
        hand_rank.point = cards[0].point;
        return true;
    }
    else 
        return false;
}

// Check to see if the pokerhand is a straight
bool PokerHand::isStraight(){
    sort(); // sort the hand
    // Check to see if pokerhand is a continuous sequence
    if (isSequence() == true){
        hand_rank.kind = Rank::hRanks::Straight;
        hand_rank.point = cards[0].point;
        return true;
    }
    else
        return false;
}

// Check to see if the pokerhand is a pair
bool PokerHand::isPair(){
    sort(); // sort the hand
       int num;
       int same = 1;
       // for loop to determine if any two cards have the same point value
       for (int i = 0; i < HANDS - 1; i++){
            if ( (same < 2) && (cards[i].point == cards[i+1].point)){
                same++;
                num = cards[i].point;
            }
        }
        if (same == 2){
            hand_rank.kind = Rank::hRanks::Pair;
            hand_rank.point = num;
            return true;
        }
        else
            return false;
}

// Checks to see if the pokerhand is a high card
bool PokerHand::isHighCard(){
    sort(); // sort the hand
    hand_rank.kind = Rank::hRanks::HighCard;
    hand_rank.point = cards[0].point;
    return true;
}

// Compare your pokerhand against another pokerhand
int PokerHand:: compareHand(const PokerHand &otherHand) const{
    // Determine who rank kind is highest
    if (this->hand_rank.kind < otherHand.hand_rank.kind)
        return -1;
    else if(this->hand_rank.kind > otherHand.hand_rank.kind)
        return 1;
    else {
        // if the rank kinds are equal, determine whose rank point is higher
        if (this->hand_rank.point < otherHand.hand_rank.point)
            return -1;
        else if (this->hand_rank.point > otherHand.hand_rank.point)
            return 1;
        else
            return 0;
    }
}

// Prints the pokerhand
void PokerHand::print() const{
    cout << "Five cards in order: " << endl;
    for (int i = 0; i < HANDS; i++){
        cards[i].print();
        cout << "    ";
    }
    cout << endl << "Its rank is: ";
    hand_rank.print();
}

//Returns the hand rank
Rank PokerHand::getRank() const{
    return hand_rank;
}

// Sets a pokerhand and then finds its rank
void PokerHand::setPokerHand(Card in_hand[], int size){
    // check to see if the card number is valid
    if (size != HANDS)
        cout << "Invalid number of cards!" << endl;
    else {
        for (int i = 0; i < size; i++)
            cards[i] = in_hand[i];
    }
    isHighCard();
    isPair();
    isThreeOfAKind();
    isStraight();
    isFlush();
    isFullHouse();
    isFourOfAKind();
    isStraightFlush();
}
