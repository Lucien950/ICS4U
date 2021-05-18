#include "Customer.h"
#include <utility>
using namespace std;

Customer::Customer(string customerName, string address, string phoneNumber) : User(move(customerName)), address(move(address)), phoneNumber(move(phoneNumber)){}

string Customer::getAddress() {return address;}
string Customer::getPhone(){return phoneNumber;}

string Customer::getUserType() {return "customer";}

bool Customer::operator==(Customer& other) {
    return (getName() == other.getName() && getAddress() == other.getAddress() && getPhone() == other.getPhone());
}

string Customer::toString() {
    return ("Customer Name: " + getName() + "\n"
         "Address: " + getAddress() + "\n"
         "Phone Number: " + getPhone() + "\n");
}
