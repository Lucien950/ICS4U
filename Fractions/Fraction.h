#ifndef CODE_FRACTION_H
#define CODE_FRACTION_H
class Fraction{
public:
    Fraction(int num, int den);
    Fraction();
    int getNum() const;
    int getDen() const;
    void setNum(int a);
    void setDen(int a);
    std::string toString() const;
    //part 2
    Fraction(Fraction const &f);
    void add(const Fraction& f);
    void subtract(const Fraction& f);
    void multiply(const Fraction& f);
    void divide(const Fraction& f);
    static Fraction add(const Fraction& f, const Fraction& g);
    static Fraction subtract(const Fraction& f, const Fraction& g);
    static Fraction multiply(const Fraction& f, const Fraction& g);
    static Fraction divide(const Fraction& f, const Fraction& g);

private:
    int numerator{};
    int denominator{};
};
#endif //CODE_FRACTION_H
