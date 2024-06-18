#pragma once
#include "person.h"
#include <string>
using namespace std;

class Lecture : public Person {
    string faculty;
    int telnumber;

public:
    Lecture(string, int, string, string, int);
    void set_faculty(string);
    string get_faculty();
    void set_telnumber(int);
    int get_telnumber();
    void display();
};
