#ifndef CODE_USER_H
#define CODE_USER_H

#include <string>
using namespace std;

class User{
private:
    string name;
public:
    string getName();

    virtual string getUserType();
    virtual string toString();

    explicit User(string name);
};

#endif //CODE_USER_H
