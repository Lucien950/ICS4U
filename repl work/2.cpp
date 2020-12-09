#include <iostream>
#include <math.h>

using namespace std;


void cubeByPointer(int &num){
    num *= 3;
}

void sumTwoInts(int &num1, int &num2){
    int sum = num1 + num2;
    num1 = sum;
    num2 = sum;
}

void circle(int radius, double &circum, double  &area){
    circum = 2.0 * radius * M_PI;
    area = radius * radius * M_PI;
}

bool quadEquation(int a, int b, int c, double &r1, double &r2){
    double fun = (-1.0 * b)/(2.0 * a);
    if(b*b < 4*a*c){
        return false;
    }
    double otherFun = sqrt(b*b - 4*a*c)/(2*a);
    r1 = fun + otherFun;
    r2 = fun - otherFun;
    return true;
}

void swapFunc(float *p1, float *p2){
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void SquareComplex(double *a, double *b){
    double tA = *a;
    double tB = *b;
    // Squares a complex number a + bi
    *a = tA*tA - tB*tB;
    *b = 2*tA*tB;
}

int main(){
    //Q1
    cout << "Q1" << endl;
    int num = 4;
    int value = 3;
    cubeByPointer(num);
    cout<< num << endl;

    //Q2
    cout << endl << "Q2" << endl;
    sumTwoInts(num, value);
    cout << num << endl << value << endl;

    //Q3
    cout << endl << "Q3" << endl;
    int r = 3;
    double cir, area;
    circle(r, cir, area);
    cout << cir << " and " << area << endl;

    //Q4
    cout << endl << "Q4" << endl;
    int a = 1;
    int b = 0;
    int c = -1;
    double r1, r2;
    quadEquation(a, b, c, r1, r2);
    cout << "Roots are " << r1 << " and " << r2 << endl;

    //Q5
    cout << endl << "Q5" << endl;
    float swap1 = 2;
    float swap2 = 4;
    cout << swap1 << endl << swap2 << endl;
    swapFunc(&swap1, &swap2);
    cout << "New Ones" << endl << swap1 << endl << swap2 << endl;

    //Q6
    cout << endl << "Q6" << endl;
    double value1 = 1;
    double value2 = 2;
    cout << value1 << " " << value2 << endl;
    SquareComplex(&value1, &value2);
    cout << value1 << " " << value2;
    return 0;
}