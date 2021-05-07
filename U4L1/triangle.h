#ifndef CODE_TRIANGLE_H
#define CODE_TRIANGLE_H

#include "shape.h"

class Triangle: public Shape{
private:
    double base, width;
public:
    Triangle(string name, double base, double width);
    double getArea();
};

#endif //CODE_TRIANGLE_H
