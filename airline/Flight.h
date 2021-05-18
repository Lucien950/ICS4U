#ifndef CODE_FLIGHT_H
#define CODE_FLIGHT_H

#include "Seat.h"
class Flight{
    Seat *seats;
    int seatCount;

public:
    //Utility
    bool checkSeatAvailable(int seatnum);
    Customer customerAtSeat(int seatnum);
    void setSeat(int seatnum, Seat seat);
    bool fullyBooked();

    //Constructor
    Flight(int seatCount);

    //Get privates
    int getSeatCount();
};

#endif //CODE_FLIGHT_H
