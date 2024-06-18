#include"student.h"
#include"lecture.h"
int main(){
    Person per("John",21,"man");
    Student stu("Marry",22,"woman","Electronics1-K53",20080001);
    Lecture lec("Michel",22,"man","Electronics Engineering",123456789);
    per.display();
    stu.display();
    lec.display();
}