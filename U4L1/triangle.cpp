#include "triangle.h"

Triangle::Triangle(string name, double base, double width): Shape(std::move(name)), base(base), width(width){}

double Triangle::getArea() {
    return 0.5 * base * width;
}
