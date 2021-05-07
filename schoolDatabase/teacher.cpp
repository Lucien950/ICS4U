#include "teacher.h"
#include <utility>
using namespace std;

Teacher::Teacher(string first, string last) : Person(move(first), move(last), "blank address"), teachables("math"), employeeId("C1234") {}
Teacher::Teacher(string f, string l, string a, string t, string id): Person(move(f), move(l), move(a)), teachables(move(t)), employeeId(move(id)){}
Teacher::Teacher(string f, string l, string t, string id): Person(move(f), move(l), "blank address"), teachables(move(t)), employeeId(move(id)){}

string Teacher::getTeachables() {return teachables;}
string Teacher::getEmployeeId() {return employeeId;}
void Teacher::setTeachables(string t) {teachables = t;}
void Teacher::setEmployeeId(string id) {employeeId = id;}



//STATICS
void Teacher::markStudentLate(Student *s) {s->addLate();}
bool Teacher::isValidId(string id) {return id.at(0) == 'C' && id.length() == 5;}

string Teacher::toString() {
    return "Teacher " + getFirstName() + " " + getLastName() + "who lives at " + getAddress() + " with ID " + getEmployeeId() + " and teachables " + getTeachables();
}
