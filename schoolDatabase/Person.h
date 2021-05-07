#ifndef CODE_PERSON_H
#define CODE_PERSON_H

#include <string>
using namespace std;

class Person{
private:
    string firstName;
    string lastName;
    string address;
    string secret;
public:
    Person(string first, string last, string add);
    string getFirstName();
    string getLastName();
    string getAddress();
    void setFirstName(string n);
    void setLastName(string n);
    void setAddress(string a);
    friend void getSecrets(Person p);
    virtual string toString();

    Person(const Person& p);
    Person& operator=(const Person &p);
    ~Person();
};
#endif //CODE_PERSON_H
