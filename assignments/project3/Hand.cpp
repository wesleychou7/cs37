// Stores and calculates attributes of a hand of cards.
#include <iostream>
#include <vector>
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
  for (int i{0}; i<5; i++){
    cout << hand[i].toString() << endl;
  }
  cout << endl;
} 

// determine if hand contains a pair
bool Hand::pair() const {
  for (int i{0}; i<faceCount.size(); i++){
    if (faceCount[i] == 2){
      return true;
    }
  }
  return false;
} 

// determine if hand contains two pairs
bool Hand::twoPair() const {
  int count = 0;

  for (int i{0}; i<faceCount.size(); i++){
    if (faceCount[i] == 2){
      count++;
    }
    if (count == 2){
      return true;
    }
  }
  return false;
} 

// determine if hand contains three of a kind
bool Hand::threeOfAKind() const {
  for (int i{0}; i<faceCount.size(); i++){
    if (faceCount[i] == 3){
      return true;
    }
  }
  return false;
} 

// determine if hand contains four of a kind
bool Hand::fourOfAKind() const {
  for (int i{0}; i<faceCount.size(); i++){
    if (faceCount[i] == 4){
      return true;
    }
  }
  return false;
} 

// determine if hand contains a flush
bool Hand::flush() const { 

  Card::Suit temp{hand[0].getSuit()};

  for (int i{1}; i<hand.size(); i++){
    if (hand[i].getSuit() != temp){
      return false;
    }
  }
  return true;
} 

// determine if hand contains a straight
bool Hand::straight() const {

  int count{0};
  int start{0};

  for (int i{0}; i<=faceCount.size(); i++){
    if (faceCount[i]==1){
      start = i;
      break;
    }
    if (i > faceCount.size()-4){
      return false;
    }
  }

  for (int j{start}; j<start+5; j++){
    if (faceCount[j]!=1){
      return false;
    }
  }
  return true;
} 