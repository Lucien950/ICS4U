#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string first, string last, string add): firstName(std::move(first)), lastName(std::move(last)), address(std::move(add)), secret("yeetus"){}


//ENCAPSULATION FUN
string Person::getFirstName() {return firstName;}
string Person::getLastName() {return lastName;}
string Person::getAddress() {return address;}
void Person::setFirstName(string n) {firstName = std::move(n);}
void Person::setLastName(string n) {lastName = std::move(n);}
void Person::setAddress(string a) {address = std::move(a);}

string Person::toString() {
    return "Oops someone didn't impliment the virtual function";
}

void getSecrets(Person p){
    cout << p.firstName << " " << p.lastName << " " << p.address << " " << p.secret;
}

Person::Person(const Person &p): firstName(p.firstName), lastName(p.lastName), address(p.address){}

Person &Person::operator=(const Person &p) {
    if(this == &p){
        return *this;
    }
    this->firstName = p.firstName;
    this->lastName = p.lastName;
    this->address = p.address;
    return *this;
}

Person::~Person()= default;
