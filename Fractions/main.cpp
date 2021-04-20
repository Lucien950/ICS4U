#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main(){
    Fraction frac1(3, 4);
    cout << "Fraction: " << frac1.toString() << endl;

    frac1.setNum(2);
    frac1.setDen(5);
    cout << "New Fraction: " << frac1.toString() << endl;

    int a = frac1.getNum();
    int b = frac1.getDen();
    cout << "Fraction put together: " << a << "/" << b << endl;
}
