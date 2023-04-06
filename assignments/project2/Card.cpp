#include <string>
#include "Card.h"

using namespace std;

Card::Card(Face cardFace, Suit cardSuit){
    face = cardFace;
    suit = cardSuit;
}

const string Card::faceNames[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", 
        "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::suitNames[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

string Card::toString() const{
    
    return faceNames[static_cast<int>(face)] + " of " + suitNames[static_cast<int>(suit)];
}