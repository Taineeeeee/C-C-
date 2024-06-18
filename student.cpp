#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string _name, int _age, string _gender, string _class, int _id)
    : Person(_name, _age, _gender) {
    class_name = _class;
    id = _id;
}

void Student::set_class(string _class) {
    class_name = _class;
}

string Student::get_class() {
    return class_name;
}

void Student::set_id(int _id) {
    id = _id;
}

int Student::get_id() {
    return id;
}

void Student::display() {
    Person::display();
    cout << "Class:\n" << class_name << endl;
    cout << "ID:\n" << id << endl;
}
