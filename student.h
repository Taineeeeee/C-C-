#pragma once
#include "person.h"
#include <string>
using namespace std;

class Student : public Person {
    string class_name;
    int id;

public:
    Student(string, int, string, string, int);
    void set_class(string);
    string get_class();
    void set_id(int);
    int get_id();
    void display();
};
