#include<iostream>
#include<cstring>

class Date{
    protected:
        int day, month, year;
    public:
        void get_birthday(int& _day, int& _month, int& _year);
        void set_birthday(int _day, int _month, int _year);
        void get_birthday_keyboard();
        void display_birthday();
};

void Date::get_birthday(int& _day, int& _month, int& _year)
{
    _month = this->month;
    _day = this->day;
    _year = this->year;
}
void Date::set_birthday(int _day, int _month, int _year)
{
    this->day = _day;
    this->month = _month;
    this->year = _year;
}
void Date::get_birthday_keyboard()
{
    std::cin >> this->day;
    std::cin >> this->month;
    std::cin >> this->year;
}
void Date::display_birthday()
{
    std::cout << day << '/' << month << '/' << year;
}

class Person{
    public:
        char name[50];
        Date birthday;
        char hometown[50];
    public:
        void set_info_keyboard();
        void display_info();
        char* get_name();
        void set_name(char _name[50]);
        char* get_hometown();    
        void set_hometown(char _hometown[50]);

};

void Person::set_info_keyboard()
{
    std::cout << std::endl << "Nhap ten: ";
    fgets(this->name, sizeof(name), stdin);

    std::cout << std::endl << "Nhap ngay thang nam sinh: ";
    this->birthday.get_birthday_keyboard();

    std::cout << std::endl << "Nhap que quan: ";
    fflush(stdin);
    fgets(this->hometown, sizeof(name), stdin);
}

void Person::display_info()
{
    std::cout << std::endl << "Ten: " << this->name;
    std::cout << std::endl << "Ngay thang nam sinh: ";
    this->birthday.display_birthday();
    std::cout << std::endl << "Que quan: " << this->hometown;
}

char* Person::get_name()
{
    return this->name;
}

char* Person::get_hometown()
{
    return this->hometown;
}

void Person::set_name(char _name[50])
{
    strcpy(this->name, _name);
}
void Person::set_hometown(char _hometown[50])
{
    strcpy(this->hometown, _hometown);
}

int main()
{
    Person Taixiu;
    Taixiu.set_name("Nguyen Cong Tai");
    Taixiu.set_hometown("36");
    Taixiu.birthday.set_birthday(1, 1, 2005);
    Taixiu.display_info();
}