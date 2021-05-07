#include "cardDeckHeaders.h"

DeckOfCards::DeckOfCards(Card *deck, int deckSize) : deck(deck), SIZE_OF_DECK(deckSize), currentCard(0){}
void DeckOfCards::shuffle() const {
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

DeckOfCards::DeckOfCards() : deck(new Card[52]), SIZE_OF_DECK(52), currentCard(0){
    for(int i = 1; i <= 13; i++){
        for(int j = 1; j <= 4; j++){
            deck[(i-1)*4 + j-1] = Card(i, j);
        }
    }
    shuffle();
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
bool DeckOfCards::moreCards() const {
    return currentCard != SIZE_OF_DECK;
}