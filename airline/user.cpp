#include <utility>

#include "User.h"

string User::getName() {
    return name;
}

User::User(string name): name(move(name)){}
string User::getUserType() {return "Non User";}
string User::toString() {return "Non User doesn't have string";}
