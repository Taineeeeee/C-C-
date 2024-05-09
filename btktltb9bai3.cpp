#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int birthDay;
    int birthMonth;
    int birthYear;
    std::string hometown;

public:
    void inputPersonInfo(Person& person) ;
    Person() ;
    void setName(std::string n) ;
    void setBirthDate(int day, int month, int year) ;
    void setHometown(std::string town);
    std::string getName() ;
    int getBirthDay() ;
    int getBirthMonth() ;
    int getBirthYear();
    std::string getHometown();
    void displayInfo() ;
};
    Person::Person() {
        name = "";
        birthDay = 0;
        birthMonth = 0;
        birthYear = 0;
        hometown = "";
    }
    void Person::inputPersonInfo(Person& person) {
    std::string name, hometown;
    int day, month, year;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    person.setName(name);

    std::cout << "Enter date of birth (day month year): ";
    std::cin >> day >> month >> year;
    person.setBirthDate(day, month, year);
    std::cin.ignore(); 

    std::cout << "Enter hometown: ";
    std::getline(std::cin, hometown);
    person.setHometown(hometown);
}

    void Person::setName(std::string n) {
        name = n;
    }

    void Person::setBirthDate(int day, int month, int year) {
        birthDay = day;
        birthMonth = month;
        birthYear = year;
    }

    void Person::setHometown(std::string town) {
        hometown = town;
    }

    std::string Person::getName() {
        return name;
    }

    int Person::getBirthDay() {
        return birthDay;
    }

    int Person::getBirthMonth() {
        return birthMonth;
    }

    int Person::getBirthYear() {
        return birthYear;
    }

    std::string Person::getHometown() {
        return hometown;
    }

    void Person::displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Date of Birth: " << birthDay << "/" << birthMonth << "/" << birthYear << std::endl;
        std::cout << "Hometown: " << hometown << std::endl;
    }



int main() {
    Person person;
    person.inputPersonInfo(person);
    std::cout << "\nPerson's Information:\n";
    person.displayInfo();
    person.setName("Taineee");
    std::cout<<"Ten moi vua nhap la: "<<person.getName()<<std::endl;
    return 0;
}