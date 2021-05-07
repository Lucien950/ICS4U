#include "student.cpp"
#include "teacher.cpp"
#include "Person.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    auto *s1 = new Student("StudentFirst", "StudentLast");
    auto *s2 = new Student("StudentFirst", "StudentLast", 10, "S123870");
    auto *s3 = new Student("StudentFirst", "StudentLast", "funnyland", 10, "S12387340");
    Student *students[3] = {s1, s2, s3};
    for(auto thisStudent : students){
        //first name, last name, address, get grades, get lates
        cout << "OLD STUDENT INFORMATION: " << thisStudent->toString() << endl;
        //get student id and isValidID
        cout << "Student ID " << thisStudent->getStudentId() << " which is " << (Student::isValidId(thisStudent->getStudentId())?"":"not ") <<  "a valid id" << endl;

        //set grade
        thisStudent->setGrade(4);
        //add late
        thisStudent->addLate();
        //set student id
        thisStudent->setStudentId("S12387340");
        cout << "NEW STUDENT INFORMATION: " << thisStudent->toString() << endl << endl;
    }

    auto *t1 = new Teacher("TeacherFirst", "TeacherLast");
    auto *t2 = new Teacher("TeacherFirst", "TeacherLast", "math", "C14");
    auto *t3 = new Teacher("TeacherFirst", "TeacherLast", "funnyland", "math", "C1234");
    Teacher *teachers[3] = {t1, t2, t3};
    for(auto thisTeacher : teachers){
        //first name, last name, address, teachables and employeeID
        cout << thisTeacher->toString() << endl;
        //get student id and isValidID
        cout << "Student ID " << thisTeacher->getEmployeeId() << " which is " << (Teacher::isValidId(thisTeacher->getEmployeeId())?"":"not ") <<  "a valid id" << endl;

        thisTeacher->setTeachables("science");
        thisTeacher->setEmployeeId("C1236");
        thisTeacher->markStudentLate(s1);
        cout << "S1 New Late Count: " << s1->getNumLates() << endl;
        cout << thisTeacher->toString() << endl << endl;
    }


    //UPCASTING
    Person *people[6] = {s1, s2, s3, t1, t2, t3};
    cout << "------------------------PEOPLE CODE------------------------" << endl;
    for(auto thisPerson: people){
        cout << "OLD DATA: " << thisPerson->toString() << endl;
        thisPerson->setFirstName("peopleName");
        thisPerson->setLastName("peopleLast");
        thisPerson->setAddress("peoplePlace");
        cout << "NEW DATA: " << thisPerson->toString() << endl << endl;
    }

    //downcasting
    Person *Joe = new Person("Joe", "Lastname", "123 sesame street");
    //enrollment
    auto * JoeStudent = (Student*) Joe;
    JoeStudent->setAddress("newLand");
    cout << JoeStudent << endl;
    cout << "JOE Address: " << JoeStudent->getAddress() << endl;


    //Friend Function
    getSecrets(*Joe);

    return 1;
}