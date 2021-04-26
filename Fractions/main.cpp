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

    Fraction frac3 = frac1;
    frac3.add(frac1);
    frac3.subtract(frac1);
    cout << "Add and subtract " << frac3.toString() << endl;

    frac3.multiply(frac1);
    frac3.divide(frac1);
    cout << "Multiple and Divide " << frac3.toString() << endl;

    //3/4 + 4/5
    cout << "Adds: " << Fraction::add(Fraction(3, 4), Fraction(4, 5)).toString() << endl;
    // 4/5 - 3/4
    cout << "Subtracts: " << Fraction::subtract(Fraction(4, 5), Fraction(3, 4)).toString() << endl;
    //3/4 * 4/5
    cout << "Multiplies: " << Fraction::multiply(Fraction(3, 4), Fraction(4, 5)).toString() << endl;
    // 3/4 divided by 4/5
    cout << "Divides: " << Fraction::divide(Fraction(3, 4), Fraction(4, 5)).toString() << endl;
}