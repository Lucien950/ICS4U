#ifndef CODE_CUSTOMER_H
#define CODE_CUSTOMER_H

#include <string>
#include "User.h"
using namespace std;

class Customer: public User{
    string address;
    string phoneNumber;
public:
    //CONSTRUCTORS
    Customer(string customerName, string address, string phoneNumber);
    //VIRTUALS
    string getUserType() override;
    string toString() override;

    //GET PRIVATES
    string getAddress();
    string getPhone();

    //OVERRIDE
    bool operator==(Customer& other);
};

#endif //CODE_CUSTOMER_H
