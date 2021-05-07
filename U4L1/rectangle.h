//
// Created by jessi on 2021-05-04.
//

#ifndef CODE_RECTANGLE_H
#define CODE_RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape{
private:
    double length, width;
public:
    Rectangle(string name, double l, double w);
    void setLength(double newL);
    void setWidth(double newW);
    double getLength();
    double getWidth();

    double getArea();
};

#endif //CODE_RECTANGLE_H
