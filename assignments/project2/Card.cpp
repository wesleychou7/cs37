#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

Card::Card(Face cardFace, Suit cardSuit){
    
    Card::Face face = cardFace;
    Card::Suit suit = cardSuit;

}

// create list

string Card::toString() const{
    return Card::face;
}