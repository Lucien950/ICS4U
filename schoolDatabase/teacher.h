#ifndef CODE_TEACHER_H
#define CODE_TEACHER_H

#include "Person.h"
#include <string>
using namespace std;

class Teacher: public Person{
private:
    string teachables;
    string employeeId;
public:
    Teacher(string first, string last);
    Teacher(string f, string l, string a, string t, string id);
    Teacher(string f, string l, string t, string id);
    string getTeachables();
    string getEmployeeId();
    void setTeachables(string t);
    void setEmployeeId(string id);
    static bool isValidId(string id);
    static void markStudentLate(Student *s);
    string toString();
};

#endif //CODE_TEACHER_H
