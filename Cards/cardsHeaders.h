#ifndef CODE_CARDSHEADERS_H
#define CODE_CARDSHEADERS_H

#include <string>
using namespace std;
class Card{
public:
    int face, suit;

    Card();
    Card(int face, int suit);
    Card(Card const &card);

    Card & operator = (Card const &card);
    friend ostream& operator << (ostream &output, Card const &card);

    static string faces[13];
    static string suits[4];
};

#endif //CODE_CARDSHEADERS_H
