#include "student.h"
#include <utility>
#include <iostream>
using namespace std;

Student::Student(string first, string last) : Person(move(first), move(last), "blank address"), grade(1), studentId("S12387340"){}
Student::Student(string f, string l, string a, int g, string id): Person(f, l, a), grade(g), studentId(id){}
Student::Student(string f, string l, int g, string id): Person(f, l, "blank address"), grade(g), studentId(id){}

bool Student::isValidId(string id) {
    return id.at(0) == 'S' && id.length() == 9;
}
string Student::toString() {
    return "Student " + getFirstName() + " " + getLastName() + " lives at " + getAddress() + " with a grade of " + to_string(getGrade()) + " and " + to_string(getNumLates()) + " lates" ;
}


//ENCAPSULATION FUN
int Student::getGrade() {return grade;}
string Student::getStudentId() {return studentId;}
int Student::getNumLates() {return numLates;}
void Student::setGrade(int n) {grade = n;}
void Student::setStudentId(string id) {this->studentId = move(id);cout << "hello" << endl;}
void Student::addLate() {numLates++;}

Student::Student(Student &s): Person(s.getFirstName(), s.getLastName(), s.getAddress()), grade(s.grade), studentId(s.studentId){}

Student &Student::operator=(Student &s) {
    if(this == &s){
        return *this;
    }
    this->setFirstName(s.getFirstName());
    this->setLastName(s.getLastName());
    this->setAddress(s.getAddress());

    return *this;
}

Student::~Student()= default;