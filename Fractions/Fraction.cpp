#include "Fraction.h"
#include<sstream>
using namespace std;

Fraction::Fraction() : numerator(1), denominator(1) {}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}
int Fraction::getNum() {return numerator;}
int Fraction::getDen() {return denominator;}
void Fraction::setNum(int a) {numerator = a;}
void Fraction::setDen(int a) {denominator = a;}

string Fraction::toString(){
    stringstream ss;
    ss << numerator << "/" << denominator;
    return ss.str();
}