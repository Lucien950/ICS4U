#include "Seat.h"

Seat::Seat(int seatNum, Customer * contact): seatNumber(seatNum), contact(*contact), available(false){}
Seat::Seat(): seatNumber(-1), contact(Customer("DEFAULT_NAME", "DEFAULT_ADDRESS", "DEFAULT_PHONENUMBER")), available(true){}

Customer Seat::getCustomer() {return contact;}
