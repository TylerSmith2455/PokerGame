/*
 * Course: CS216-001
 * Project: Project 2
 * Purpose: Simplified Texas Holdem game
 * Author: Tyler Smith
 */
#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

// set constant numbers
const int TOTALCARDS = 7;   // each player gets 7 total cards
const int HANDS = 5;        // each player plays 5 cards in their hand

// Find the best five cards for a poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main(){
    // user input variable
    char input = ' ';
    do {
        
        cin.clear();

    // Create a deck of 52 cards and shuffle the deck
    Deck playDeck;
    playDeck.createDeck();
    playDeck.shuffleDeck();
    
    // Create a vector of cards for Player 1 and Player 2
    vector<Card> Player1;
    vector<Card> Player2;
    vector<Card> SharedCards;

    // Deal Player 1 two cards
    Player1.push_back(playDeck.deal_a_card());
    Player1.push_back(playDeck.deal_a_card());
    cout << "The cards in your hand are:" << endl << "   ";
    Player1[0].print();
    cout << endl << "    ";
    Player1[1].print();
    cout << endl << endl;

    // Deal Five cards to share between the two players
    cout << "The FIVE cards on the deck to share are:" << endl;
    cout << "    *************************" << endl;
    for (int i = 0; i < HANDS; i++){
        SharedCards.push_back(playDeck.deal_a_card());
        cout << "    *   ";
        SharedCards[i].print();
        cout << "        *" << endl;
    }
    cout << "    *************************" << endl;

    // Deal Player 2 two cards
    Player2.push_back(playDeck.deal_a_card());
    Player2.push_back(playDeck.deal_a_card());
    cout << "The cards in computer's hand are:" << endl << "   ";
    Player2[0].print();
    cout << endl << "    ";
    Player2[1].print();
    cout << endl << endl;

    // Add the shared cards to both of the Players cards
    for (int i = 0; i < HANDS; i++){
        Player1.push_back(SharedCards[i]);
        Player2.push_back(SharedCards[i]);
    }

    // Create poker hands for both Players
    PokerHand Player1Hand;
    PokerHand Player2Hand;

    // Find the players best poker hands
    Player1Hand = best_FIVE_out_of_SEVEN(Player1);
    Player2Hand = best_FIVE_out_of_SEVEN(Player2);

    // Print the players best poker hands
    cout << "Player 1: You" << endl;
    Player1Hand.print();

    cout << endl << endl << endl << endl;
    cout << "Player 2: Computer" << endl;
    Player2Hand.print();
    cout << endl << endl << endl;

    // Check to see who wins
    if (Player1Hand.compareHand(Player2Hand) == -1)
        cout << "Sorry, the computer wins the game!" << endl;
    else if (Player1Hand.compareHand(Player2Hand) == 1)
        cout << "Congratulations, you win the game!" << endl;
    else
        cout << "It is a tie game!" << endl;
    cout << "Do you want to play poker game again (Press ""q"" or ""Q"" to quit the program)";
    cin.get(input);
    } while (input != 'Q' && input != 'q');

}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards) {
      PokerHand bestH;
      PokerHand cardsH;
 
      // check if the parameter is valid
      if (cards.size() != TOTALCARDS) {
          cout << "Invalid Cards, we need SEVEN cards!" << endl;
          return cardsH; // return a PokerHand object by default constructor
      }
 
      // Find the best 5 cards out of the 7 cards
      for (int i=0; i < TOTALCARDS; i++) {
          for (int j=i+1; j < TOTALCARDS; j++) {
              Card pick[HANDS];
          int index = 0;
 
          // Iterate over all seven cards and assign them to the pick [] array
          // exclude cards with index numbers of #i and #j
          for (int k=0; k < TOTALCARDS; k++) {
              if (k == i || k == j)
                  continue;
              pick[index] = cards[k];
              index++;
          }
 
          // create a PokerHand with pick[]
          cardsH.setPokerHand(pick, HANDS);
 
          // Check to see if current pick is better than
          // the best you have seen so far
          if (bestH.compareHand(cardsH) < 0){
              bestH = cardsH;
          }
         }
     }

     // Now bestH holds the best poker hand among all possible poker hands
    // cout << "*** Best five-card hand ***" << endl;
//        bestH.print();
  //   cout << endl << endl;
     return bestH;
 }


