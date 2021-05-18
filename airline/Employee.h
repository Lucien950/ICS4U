#ifndef CODE_EMPLOYEE_H
#define CODE_EMPLOYEE_H

#include "User.h"
class Employee: public User{
public:
    //CONSTRUCTORS
    Employee(string name);

    //VIRTUALS
    string getUserType() override;
    string toString() override;
};
#endif //CODE_EMPLOYEE_H
