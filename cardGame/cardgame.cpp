#include <string>
#include <map>
#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>
//UTILITY


//SHUFFLES DECK
void swap (string *a, string *b){
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

//TEST IF ALL VALUES IN AN ARRAY ARE UNIQUE
bool areUnique(const int arr[], const int size){
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}
//CHECKS IF ALL VALUES ARE BETWEEN 1-4
bool goodValues(const int arr[], const int size){
    for(int i = 0; i < size; i++){
        if(!(arr[i] <= 4 && arr[i] > 0)){
            return false;
        }
    }
    return true;
}

//CONVERT STRING CARD NUMBER TO INT
int number(string card){
    string bucket;

    bool go = true;
    int onIndex = 0;
    while(go){
        if(card[onIndex] == ' '){
            go = false;
        }else{
            bucket += card[onIndex];
            onIndex++;
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
//CONVERT CARD STRING INTO SUIT INDEX
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
        onIndex++;
    }

    map<string, int> dict = {
        {"Hearts",14},
        {"Diamonds",2},
        {"Clubs",3},
        {"Spades",4}
    };

    return dict[bucket];
}

//CATCH ALL FUNCTION TO COMPARE CARDS
int compareCards(const string& card1, const string& card2){
	if(card1 == card2){
		return -1;
	}

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
    }

    return -1;
}

//CHECK IF EVERY VALUE OF AN ARRAY IS EMPTY??
bool empty(const string arr[], int size){
    for(int i = 0; i <  size; i++){
    	if(arr[i] == "*"){
    		continue;
    	}
        if(!arr[i].empty()){
            return false;
        }
    }
    return true;
}

//COPY ONE ARRAY TO ANOTHER
void copy(string arr1[52], string arr2[52]){
    for(int i = 0; i < 52; i++){
        arr1[i] = arr2[i];
    }
}

void printARR(string arr, int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
}



int main(){
	//=====================PREGAME=====================
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
    string * discard1;
    discard1 = new string[52];
    string * discard2;
	discard2 = new string[52];



    //=====================GAME TIME=====================
	int c1Counter = 0;
	int c2Counter = 0;
    while(true) {
        int order1[4];
        int order2[4];
        string hand1[4];//Put in the first four cards
        string hand2[4];//Same thing
        int handSize = 0;

        //DRAW HAND
        while (handSize < 4) {
            //MOVE DISCARD TO Draw stack
            if(empty(cards1, 52)){
				if(empty(discard1, 52)){
					cout << "Player 1 ran out of cards, Player 2 Wins!" << endl;
					return 0;
				}
				c1Counter = 0;
				copy(cards1, discard1);

				delete[] discard1;
				discard1 = new string[52];
				discard1Fill = 0;
			}
            if(empty(cards2, 52)){
				if(empty(discard2, 52)){
					cout << "Player 2 ran out of cards, Player 1 Wins!" << endl;
					return 0;
				}
				c2Counter = 0;
				copy(cards2, discard2);

				delete[] discard2;
				discard2 = new string[52];
				discard2Fill = 0;
			}


            if (cards1[c1Counter] != "*") {
                hand1[handSize] = cards1[c1Counter];
                cards1[c1Counter] = "*";
            }
            if(cards2[c2Counter] != "*"){
				hand2[handSize] = cards2[c2Counter];
				cards2[c2Counter] = "*";
            }
			handSize++;
            c1Counter++;
            c2Counter++;
        }


        //=====================GET INPUT FROM PLAYERS=====================
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
            if (!areUnique(order1, 4) || !goodValues(order1, 4)) {
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
            if (!areUnique(order2, 4) || !goodValues(order2, 4)) {
                continue;
            }

            badOrder = false;
        }

        //COMPARE ALL FOUR CARDS
        for (int i = 0; i < 4; i++) {
        	string card1 = hand1[order1[i]-1];
        	string card2 = hand2[order2[i]-1];
            int winner = compareCards(card1, card2);
            if (winner == 1) {
            	cout << "Player 1 won the battle between " << card1 << " " << card2 << endl;
                discard1[discard1Fill] = card1;
                discard1[discard1Fill + 1] = card2;
                discard1Fill += 2;
            } else if (winner == 2) {
				cout << "Player 2 won the battle between " << card1 << " " << card2 << endl;
				discard2[discard2Fill] = card1;
                discard2[discard2Fill + 1] = card2;
                discard2Fill += 2;
            } else if (winner == 0){
            	cout << "YA FUCKIN BROKE THE CODE EDWIN " << card1 << " " << card2 << endl;
            	return 0;
            }
        }



        //CHEATS (REMOVE IF YOU WANT TO PLAY PROPERLY
		delete[] discard2;
        discard2 = new string[52];
        for(auto & i : cards2){
        	i = "*";
        }
    }
}