#include "Cards.cpp"
#include "DeckCards.cpp"
#include <iostream>
using namespace std;

int main(){
    Card *card = new Card(3, 4);
    cout << Card::faces[card->face] << " " << Card::suits[card->suit] << endl;
    cout << card << endl;
    Card card1 = *card;
    delete card;
    cout << card1 << endl;


    Card * deckList = new Card[4];

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> distCards(1,13);
    uniform_int_distribution<std::mt19937::result_type> distSuit(1,4);
    for(int i = 0; i < 4; i++){
        deckList[i] = Card(distCards(rng), distSuit(rng));
    }

    DeckOfCards deck = DeckOfCards(deckList, 4);

    cout << deck.SIZE_OF_DECK << " " << deck.currentCard << " " << deck.moreCards() << endl;
    for(int i = 0; i < 4; i++){
        cout << deck.dealCard() << endl;
    }
    cout << "-------" << endl;
    deck.currentCard = 0;
    deck.shuffle();
    for(int i = 0; i < 4; i++) {
        cout << deck.dealCard() << endl;
    }
    delete[] deckList;

    cout << endl << "SHUFFLED FULL DECK -------" << endl;
    DeckOfCards deck2 = DeckOfCards();
    for(int i = 0; i < deck2.SIZE_OF_DECK; i++){
        cout << deck2.dealCard() << endl;
    }


    return 1;
}
