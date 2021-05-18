#include "Flight.h"
#include <iostream>
#include <utility>
using namespace std;

Flight::Flight(int seatCount): seats(new Seat[seatCount]), seatCount(seatCount){}

bool Flight::fullyBooked() {
    for(int i = 0;i < seatCount; i++){
        if(seats[i].available){
            return false;
        }
    }
    return true;
}

bool Flight::checkSeatAvailable(int seatnum) {
    return seats[seatnum].available;
}

void Flight::setSeat(int seatnum, Seat seat) {seats[seatnum] = move(seat);}

Customer Flight::customerAtSeat(int seatnum) {return seats[seatnum].getCustomer();}

int Flight::getSeatCount() {return seatCount;}
