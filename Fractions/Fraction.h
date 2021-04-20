#ifndef CODE_FRACTION_H
#define CODE_FRACTION_H
class Fraction{
public:
    Fraction(int num, int den);
    Fraction();
    int getNum();
    int getDen();
    void setNum(int a);
    void setDen(int a);
    std::string toString();
private:
    int numerator;
    int denominator;
};
#endif //CODE_FRACTION_H
