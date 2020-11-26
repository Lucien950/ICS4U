#include <string>
#include <map>
#include <iostream>

using namespace std;

#include <cstdlib>
#include <ctime>
//UTILITY
void swap (string *a, string *b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}
void randomize (string arr[], int n){
    srand (time(nullptr));
    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}
bool areUnique(const int arr[]){
    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = i + 1; j < 4; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}
bool goodValues(const int arr[]){
    for(int i = 0; i < *(&arr + 1) - arr; i++){
        if(arr[i] <= 4 && arr[i] > 0){
            return false;
        }
    }
    return true;
}

int number(string card){
    string bucket;

    bool go = true;
    int onIndex = 0;
    while(go){
        if(card[onIndex] == ' '){
            go = false;
        }else{
            bucket += card[onIndex];
        }
    }

    map<string, int> dict = {
        {"Ace",14},
        {"Deuce",2},
        {"Three",3},
        {"Four",4},
        {"Five",5},
        {"Six",6},
        {"Seven",7},
        {"Eight",8},
        {"Nine",9},
        {"Ten",10},
        {"Jack",11},
        {"Queen",12},
        {"King",13}
    };

    return dict[bucket];
}
int suit(string card){
    string bucket;

    bool go = true;
    int onIndex = 0;
    int spaceCount = 0;
    int cardSize = card.length();

    while(go){
        if(card[onIndex] == ' '){
            spaceCount += 1;
        }
        else if(spaceCount == 2){
            if(onIndex >= cardSize){go = false;}
            else{
                bucket += card[onIndex];
            }
        }
    }

    map<string, int> dict = {
        {"Hearts",14},
        {"Diamonds",2},
        {"Clubs",3},
        {"Spades",4}
    };

    return dict[bucket];
}
int compareCards(string card1, string card2){
    if (number(card1) > number(card2)){
        return 1;
    }else if (number(card1) < number(card2)){
        return 2;
    }else{
        if(suit(card1) > suit(card2)){
            return 1;
        }else if (suit(card1) < suit(card2)){
            return 2;
        }

        //BAD???
        return 0;
    }
}

bool empty(const string arr[]){
    for(int i = 0; i <  *(&arr + 1) - arr; i++){
        if(!arr[i].empty()){
            return false;
        }
    }
    return true;
}

void copy(string arr1[52], string arr2[52]){
    for(int i = 0; i < 52; i++){
        arr1[i] = arr2[i];
    }
}


int main(){
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string faces[13] = {"Ace", "Deuce", "Three" ,"Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string cards[52];
    int counter = 0;

    //SET CARDS
    for(const string &suit: suits){
        for(const string &face: faces){
            cards[counter] = face + " of " + suit;
            counter++;
        }
    }

    //SHUFFLE DECK
    randomize(cards, sizeof(cards) / sizeof(cards[0]));

    //Separate Deck
    string cards1[52];
    string cards2[52];
    for(int i = 0; i < 52; i++){
        if(i<26){
            cards1[i] = cards[i];
        }else{
            cards2[i-26] = cards[i];
        }
    }

    int discard1Fill = 0;
    int discard2Fill = 0;
    string discard1[52];
    string discard2[52];



    //EACH Game
    bool game = true;
    while(game) {
        int order1[4];
        int order2[4];
        string hand1[4];//Put in the first four cards
        string hand2[4];//Same thing
        int handSize = 0;
        counter = 0;

        //DRAW HAND
        while (handSize < 4) {
            //MOVE DISCARD TO Draw stack
            if(counter > 52){
                counter = 0;

                //TEST ENDGAME STATE
                if(empty(discard1)){
                    cout << "Player 1 ran out of cards, Player 2 Wins!" << endl;
                    return 0;
                }else if(empty(discard2)){
                    cout << "Player 2 ran out of cards, Player 1 Wins!" << endl;
                    return 0;
                }

                //Actual Action
                copy(cards1, discard1);
                copy(cards2, discard2);
            }


            if (cards[counter] != "*") {
                hand1[handSize] = cards1[counter];
                hand2[handSize] = cards1[counter];
                cards1[counter] = "*";
                cards2[counter] = "*";
                handSize++;
            }
            counter++;
        }

        //DISPLAY INFO FOR PLAYER 1
        cout << "Player 1: Choose the order you play your cards" << endl;
        for (int i = 1; i <= 4; i++) {
            cout << i << "- " << hand1[i - 1] << endl;
        }
        //GET VALUES
        bool badOrder = true;
        while (badOrder) {
            cin >> order1[0] >> order1[1] >> order1[2] >> order1[3];

            //CHECK IF ALL VALUES ARE UNIQUE
            if (!areUnique(order1) || !goodValues(order1)) {
                cout << "Oops bad input. Try again" << endl;
                continue;
            }

            badOrder = false;
        }

        //DISPLAY INFO FOR PLAYER 2
        cout << "Player 2: Choose the order you play your cards" << endl;
        for (int i = 1; i <= 4; i++) {
            cout << i << "- " << hand2[i - 1] << endl;
        }
        //GET VALUES
        badOrder = true;
        while (badOrder) {
            cin >> order2[0] >> order2[1] >> order2[2] >> order2[3];

            //CHECK IF ALL VALUES ARE UNIQUE
            if (!areUnique(order2) || !goodValues(order2)) {
                continue;
            }

            badOrder = false;
        }

        //COMPARE ALL FOUR CARDS
        for (int i = 0; i < 4; i++) {
            int winner = compareCards(hand1[order1[i]-1], hand2[order2[i]-1]);
            if (winner == 1) {
                discard1[discard1Fill] = hand1[order1[i]];
                discard1[discard1Fill + 1] = hand2[order2[i]];
                discard1Fill += 2;
            } else if (winner == 2) {
                discard2[discard1Fill] = hand1[order1[i]];
                discard2[discard1Fill + 1] = hand2[order2[i]];
                discard2Fill += 2;
            }
        }

        //JUST TO SUPPRESS ERROR
        game = false;
    }

    return 0;
}