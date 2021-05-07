#include "circle.h"

Circle::Circle(string name, double r): Shape(move(name)), radius(r){}

double Circle::getRadius() {return radius;}
void Circle::setRadius(double newRadius) {radius = newRadius;}

double Circle::getArea() {
    return 3.141592654 * radius;
}
