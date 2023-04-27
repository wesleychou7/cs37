#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

// Define card structure with rank and suit
struct Card {
    string rank;
    string suit;
};

// Function to display a card
void displayCard(Card card) {
    cout << card.rank << " of " << card.suit << endl;
}

// Function to create a deck of 52 cards
vector<Card> createDeck() {
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<Card> deck;

    for (string rank : ranks) {
        for (string suit : suits) {
            deck.push_back({rank, suit});
        }
    }
    return deck;
}

// Function to shuffle a deck of cards
void shuffleDeck(vector<Card>& deck) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

// Function to deal cards to players
void dealCards(vector<Card>& deck, vector<Card>& player1, vector<Card>& player2) {
    for (int i = 0; i < 5; i++) {
        player1.push_back(deck.back());
        deck.pop_back();
        player2.push_back(deck.back());
        deck.pop_back();
    }
}

// Function to evaluate the rank of a hand
int evaluateHand(vector<Card> hand) {
    // Declare ranks vector
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    // Sort hand by rank
    sort(hand.begin(), hand.end(), [&ranks](Card a, Card b) {
        return find(ranks.begin(), ranks.end(), a.rank) < find(ranks.begin(), ranks.end(), b.rank);
    });

    // Check for flush
    bool flush = true;
    for (int i = 1; i < 5; i++) {
        if (hand[i].suit != hand[0].suit) {
            flush = false;
            break;
        }
    }

    // Check for straight
    bool straight = true;
    for (int i = 1; i < 5; i++) {
        if (find(ranks.begin(), ranks.end(), hand[i].rank) - find(ranks.begin(), ranks.end(), hand[i-1].rank) != 1) {
            straight = false;
            break;
        }
    }

    // Check for straight flush
    if (flush && straight) {
        return 9;
    }

    // Check for four of a kind
    if (hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank) {
        return 8;
    }

    // Check for full house
    if ((hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank) || (hand[0].rank == hand[1].rank && hand[2].rank == hand[4].rank)) {
        return 7;
    }

    // Check for flush
    if (flush) {
        return 6;
    }

    // Check for straight
    if (straight) {
        return 5;
    }

    // Check for three of a kind
    if (hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank || hand[2].rank == hand[4].rank) {
        return 4;
    }

    // Check for two pairs
    if ((hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) || (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank) || (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank)) {
        return 3;
    }

    // Check for one pair
    for (int i = 0; i < 4; i++) {
        if (hand[i].rank == hand[i+1].rank) {
            return 2;
        }
    }

    // High card
    return 1;
}

vector<Card> initializeDeck() {
    vector<Card> deck;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            Card card = {rank, suit};
            deck.push_back(card);
        }
    }
    return deck;
}

void printHand(const vector<Card>& hand) {
    for (int i = 0; i < hand.size(); i++) {
        cout << getRankString(hand[i].rank) << " of " << getSuitString(hand[i].suit);
        if (i < hand.size() - 1) {
            cout << ", ";
        }
    }
}



int main() {
    // Initialize deck
    vector<Card> deck = initializeDeck();

    // Shuffle deck
    shuffleDeck(deck);

    // Deal cards to players
    vector<Card> player1, player2;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            player1.push_back(deck.back());
            deck.pop_back();
        } else {
            player2.push_back(deck.back());
            deck.pop_back();
        }
    }

    // Evaluate hands
    int player1Rank = evaluateHand(player1);
    int player2Rank = evaluateHand(player2);

    // Output hands
    cout << "Player 1's hand: ";
    printHand(player1);
    cout << endl;
    cout << "Player 2's hand: ";
    printHand(player2);
    cout << endl;

    // Output results
    if (player1Rank > player2Rank) {
        cout << "Player 1 wins with a rank of " << player1Rank << endl;
    } else if (player2Rank > player1Rank) {
        cout << "Player 2 wins with a rank of " << player2Rank << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
    return 0;
}

