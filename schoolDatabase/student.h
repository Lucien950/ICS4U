#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student: public Person{
private:
    int grade{};
    string studentId;
    int numLates{};
public:
    Student(string first, string last);
    Student(string f, string l, string a, int g, string id);
    Student(string f, string l, int g, string id);
    int getGrade();
    string getStudentId();
    int getNumLates();
    void setGrade(int n);
    void setStudentId(string id);
    void addLate();
    string toString() override;
    static bool isValidId(string id);

    Student(Student &s);
    Student& operator=(Student &p);
    ~Student();
};
#endif //CODE_STUDENT_H
