#include <iostream>
#include "Car.h"

using namespace std;

void Car::beep() {
    cout << "BEEPP!!" << endl;
}

void Car::drive() {
    cout << "We are driving to " << destination << " at " << speed << "kph" << endl;
}
