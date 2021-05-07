#include "shape.h"

Shape::Shape(string name): name(move(name)) {}

void Shape::setName(string newName) {name = newName;}
string Shape::getName() {return name;}