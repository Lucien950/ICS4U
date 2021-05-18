#include "Employee.h"
#include <utility>
Employee::Employee(string name) : User(move(name)){}

string Employee::getUserType() {return "employee";}

string Employee::toString() {
    return "Employee " + getName();
}
