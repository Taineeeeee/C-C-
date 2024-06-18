#include <iostream>
#include "lecture.h"
using namespace std;

Lecture::Lecture(string _name, int _age, string _gender, string _faculty, int _telnumber)
    : Person(_name, _age, _gender) {
    faculty = _faculty;
    telnumber = _telnumber;
}

void Lecture::set_faculty(string _faculty) {
    faculty = _faculty;
}

string Lecture::get_faculty() {
    return faculty;
}

void Lecture::set_telnumber(int _telnumber) {
    telnumber = _telnumber;
}

int Lecture::get_telnumber() {
    return telnumber;
}

void Lecture::display() {
    Person::display();
    cout << "Faculty:\n" << faculty << endl;
    cout << "Telephone Number:\n" << telnumber << endl;
}
