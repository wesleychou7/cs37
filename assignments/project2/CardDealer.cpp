#include <iostream>
#include <iomanip>
#include "DeckOfCards.h"
using namespace std;

int main() {
   DeckOfCards myDeckOfCards;
   myDeckOfCards.shuffle(); // place Cards in random order

   cout << endl;
   // print all 52 Cards in the order in which they are dealt
   for (int i = 1; myDeckOfCards.moreCards(); ++i) {
      // deal and display a Card
      cout << left << setw(19) << myDeckOfCards.dealCard().toString();

      if (i % 4 == 0) { // output newline every 4 cards
         cout << endl;
      }
   } 
   cout << endl;
} 
