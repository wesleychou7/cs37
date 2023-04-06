#include <vector>
#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

vector<Card> deck;

DeckOfCards::DeckOfCards(){
    currentCard = 0;
    for (int i{0}; i < 4; i++){
        for (int j{0}; j < 13; j++){
            Card card(static_cast<Card::Face>(j), static_cast<Card::Suit>(i));
            deck.push_back(card);
        }
    }
}

void DeckOfCards::shuffle(){
    int randInd;
    for(int i = 0; i < 52; ++i){
        randInd = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[randInd];
        deck[randInd] = temp;
    }
}

Card DeckOfCards::dealCard(){
    return deck[currentCard++];
}

bool DeckOfCards::moreCards() const{
    bool mCard = currentCard < 52;
    return mCard;
}

