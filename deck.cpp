// File: deck.cpp
// Course: CS216 - 001
// Project: Lab 8 Part 2
// Purpose: the implementation of member functions for the Deck class.
// Author: Tyler Smith

#include "deck.h"

// Creates a 52 card deck of playing cards
void Deck::createDeck(){
    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++)
    {    
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }
}

// Shuffles the 52 card deck randomly
void Deck::shuffleDeck(){
    srand(time(0));
    Card temp;  // for swapping
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// Takes one card out of the deck
Card Deck::deal_a_card(){
    int cardNum = deck.size() - 1;
    Card card = deck[cardNum];
    deck.pop_back();
    return card;
}
