#include <random>
#include <iostream>
#include "cardsHeaders.h"

using namespace std;

string Card::faces[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string Card::suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};


Card::Card() {
    face = 1;
    suit = 1;
}
Card::Card(int face, int suit){
    if(face < 1 || face > 13 || suit < 1 || suit > 4){
        throw "FACE/SUIT OUT OF RANGE";
    }
    this->face = face;
    this->suit = suit;
}
Card::Card(const Card &card): face(card.face), suit(card.suit){}
Card& Card::operator = (const Card &card){
    if (this != &card) {
        suit = card.suit;
        face = card.face;
    }
    return *this;
}
ostream &operator<< (ostream &output, Card const &card){
    output << Card::faces[card.face-1] + " " + Card::suits[card.suit-1];
    return output;
}



DeckOfCards::DeckOfCards(Card *deck, int deckSize) : deck(deck), SIZE_OF_DECK(deckSize), currentCard(0){}
void DeckOfCards::shuffle() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,SIZE_OF_DECK-1);

    for(int i = 0; i < SIZE_OF_DECK; i++){
        int other = dist(rng);
        Card temp = deck[i];
        deck[i] = deck[other];
        deck[other] = temp;
    }
}
Card DeckOfCards::dealCard() {
    if(!moreCards()){
        throw "No More Cards Exception";
    }
    else{
        currentCard += 1;
        return deck[currentCard-1];
    }
}
bool DeckOfCards::moreCards() {
    return !(currentCard == SIZE_OF_DECK);
}
