#ifndef CODE_SEAT_H
#define CODE_SEAT_H


#include "Customer.h"
class Seat{
    int seatNumber;
    Customer contact;
public:
    bool available;
    Customer getCustomer();
    Seat(int seatNum, Customer * contact);
    Seat();
};

#endif //CODE_SEAT_H
