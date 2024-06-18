#include <iostream>
#include "person.h"
using namespace std;

Person::Person(string _name, int _age, string _gender) {
    name = _name;
    age = _age;
    gender = _gender;
}

string Person::get_name() {
    return name;
}

void Person::set_name(string _name) {
    name = _name;
}

int Person::get_age() {
    return age;
}

void Person::set_age(int _age) {
    age = _age;
}

string Person::get_gender() {
    return gender;
}

void Person::set_gender(string _gender) {
    gender = _gender;
}

void Person::display() {
    cout << "Person:\n";
    cout << "Name:\n" << name << endl;
    cout << "Age:\n" << age << endl;
    cout << "Gender:\n" << gender << endl;
}
