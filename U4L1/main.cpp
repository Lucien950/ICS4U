#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main(){
    auto *c = new Circle("CircleName", 2);
    auto *t = new Triangle("Triangle Name", 2, 4);
    auto *r = new Rectangle("Rectangle Name", 2, 5);
    Shape* shapes[3] = {c, t, r};
    for(auto & shape : shapes){
        cout << shape->getArea() << endl;
    }
    return 1;
}