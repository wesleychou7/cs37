// Stores and calculates attributes of a hand of cards.
#include <iostream>
#include "Hand.h"
using namespace std;

// constructor takes 5 cards from Deck; it assumes 5 cards are available
Hand::Hand(DeckOfCards &deck) : faceCount(Card::FACES) {
   // get hand from deck
   for (unsigned i{0}; i < 5; ++i) {
      hand.push_back(deck.dealCard());
   }

   // count number of times each face appears (for later use)
   for (unsigned i{0}; i < hand.size(); ++i) {
      ++faceCount[static_cast<int>(hand[i].getFace())];
   }
} 

// display contents of hand to standard output stream
void Hand::print() const {
  //
  // TO DO
  //
} 

// determine if hand contains a pair
bool Hand::pair() const {
  //
  // TO DO
  //
} 

// determine if hand contains two pairs
bool Hand::twoPair() const {
  //
  // TO DO
  //
} 

// determine if hand contains three of a kind
bool Hand::threeOfAKind() const {
  //
  // TO DO
  //
} 

// determine if hand contains four of a kind
bool Hand::fourOfAKind() const {
  //
  // TO DO
  //
} 

// determine if hand contains a flush
bool Hand::flush() const { 
  //
  // TO DO
  //
} 

// determine if hand contains a straight
bool Hand::straight() const {
  //
  // TO DO
  //
} 