#include <random>
#include "cardsHeaders.h"

using namespace std;

string Card::faces[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string Card::suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};


Card::Card() : face(1), suit(1) {}
Card::Card(int face, int suit){
    if(face < 1 || face > 13 || suit < 1 || suit > 4){
        throw "FACE/SUIT OUT OF RANGE";
    }
    this->face = face-1;
    this->suit = suit-1;
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
    output << Card::faces[card.face] + " " + Card::suits[card.suit];
    return output;
}