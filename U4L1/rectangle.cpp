#include "rectangle.h"

Rectangle::Rectangle(string name, double l, double w): Shape(move(name)), length(l), width(w){}
void Rectangle::setLength(double newL) {length = newL;}
void Rectangle::setWidth(double newW) {width = newW;}

double Rectangle::getLength() {return length;}
double Rectangle::getWidth() {return width;}

double Rectangle::getArea() {
    return length * width;
}
