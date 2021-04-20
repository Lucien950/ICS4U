#include "Car.cpp"

using namespace std;

int main(){
    Car car1;
    car1.drive();
    car1.beep();

    Car car2;
    car2.speed = 10;
    car2.drive();
    car2.beep();
}