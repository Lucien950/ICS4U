#include "Fraction.h"
#include <sstream>
#include <algorithm>

using namespace std;

int lcm(int a, int b){
    return (a*b)/__gcd(a, b);
}

Fraction::Fraction() : numerator(1), denominator(1) {}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}
int Fraction::getNum() const {return numerator;}
int Fraction::getDen() const {return denominator;}
void Fraction::setNum(int a) {numerator = a;}
void Fraction::setDen(int a) {denominator = a;}

string Fraction::toString() const{
    stringstream ss;
    ss << numerator << "/" << denominator;
    return ss.str();
}

//part 2
//new constructor
Fraction::Fraction(Fraction const &f): numerator(f.numerator), denominator(f.denominator){}

//Internal functions
void Fraction::add(const Fraction& f){
    Fraction newFrac = Fraction::add(Fraction(numerator, denominator), f);
    numerator = newFrac.numerator;
    denominator = newFrac.denominator;
}
void Fraction::subtract(const Fraction& f){
    Fraction newFrac = Fraction::subtract(Fraction(numerator, denominator), f);
    numerator = newFrac.numerator;
    denominator = newFrac.denominator;
}
void Fraction::multiply(const Fraction& f){
    Fraction newFrac = Fraction::multiply(Fraction(numerator, denominator), f);
    numerator = newFrac.numerator;
    denominator = newFrac.denominator;
}
void Fraction::divide(const Fraction& f){
    Fraction newFrac = Fraction::divide(Fraction(numerator, denominator), f);
    numerator = newFrac.numerator;
    denominator = newFrac.denominator;
}

//STATIC FUNCTIONS
Fraction Fraction::add(const Fraction& f, const Fraction& g){
    Fraction out;
    int newDen = lcm(f.denominator, g.denominator);
    out.numerator = f.numerator * (newDen / f.denominator) + g.numerator * (newDen / g.denominator);
    out.denominator = newDen;
    return out;
}
Fraction Fraction::subtract(const Fraction& f, const Fraction& g){
    Fraction out;
    int newDen = lcm(f.denominator, g.denominator), fNewNum = f.numerator * (newDen / f.denominator), gNewNum = g.numerator * (newDen / g.denominator);
    out.numerator = fNewNum - gNewNum;
    out.denominator = newDen;
    return out;
};
Fraction Fraction::multiply(const Fraction& f, const Fraction& g){
    return Fraction(f.numerator * g.numerator, f.denominator * g.denominator);
};
Fraction Fraction::divide(const Fraction& f, const Fraction& g){
    Fraction out(f.numerator * g.denominator, f.denominator * g.numerator);
    int lcd = __gcd(out.numerator, out.denominator);
    out.numerator /= lcd;
    out.denominator /= lcd;
    return out;
};