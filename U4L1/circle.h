#ifndef CODE_CIRCLE_H
#define CODE_CIRCLE_H

#include "shape.h"
class Circle: public Shape{
private:
    double radius;
public:
    Circle(string name, double r);
    void setRadius(double newRadius);
    double getRadius();
    double getArea();
};

#endif //CODE_CIRCLE_H
