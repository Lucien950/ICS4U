#ifndef CODE_SHAPE_H
#define CODE_SHAPE_H


#include <string>
#include <utility>
using namespace std;

class Shape{
private:
    string name;
public:
    Shape(string name);
    void setName(string newName);
    string getName();

    virtual double getArea() = 0;
};
#endif //CODE_SHAPE_H
