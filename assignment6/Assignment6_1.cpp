#include <iostream>
using namespace std;

// Date class
class Date
{
    // private data members
private:
    int day;
    int month;
    int year;

    // data functions
public:
    // parameter less constructor // default day - -99/-99/1970
    Date()
    {
        this->day = -99;
        this->month = -99;
        this->year = 1970;
    }

    // parameterised constructor
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // Inspectors
    int get_day()
    {
        return this->day;
    }
    int get_month()
    {
        return this->month;
    }
    int get_year()
    {
        return this->year;
    }

    // Mutators

    void set_day(int day)
    {
        this->day = day;
    }

    void set_month(int month)
    {
        this->month = month;
    }

    void set_year(int year)
    {
        this->year = year;
    }

    // Accept function

    void accept()
    {
        cout << "Please Enter day : ";
        cin >> this->day;
        cout << "Please Enter month : ";
        cin >> this->month;
        cout << "Please Enter year : ";
        cin >> this->year;
    }

    // Display function;

    void display()
    {

        cout << "Day : " << this->day << endl;
        cout << "Month : " << this->month << endl;
        cout << "Year : " << this->year << endl;
    }

    // Checking for leap year

    bool is_leap_year()
    {
        if ((this->year % 400 == 0) || (this->year % 100 != 0) && (this->year % 4 == 0))
        {
            cout << "leap year" << endl;
            return true;
        }
        cout << "Not a leap year" << endl;
        return false;
    }
};

// Employee class
class Employee
{
    // private data members
private:
    int id;
    float sal;
    string dept;
    Date joining;

    // member functions
public:
    // parameterless constructor // default = -99
    Employee()
    {
        this->id = -99;
        this->dept = "-99";
        this->sal = -99;
    }

    // parameterized construrtor
    Employee(int id, float sal, string dept, int day, int month, int year) : joining(day, month, year)

    {
        this->id = id;
        this->dept = dept;
        this->sal = sal;
    }

    // Inspectors
    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }
    string get_dept()
    {
        return this->dept;
    }

    Date get_joining()
    {
        return this->joining;
    }

    // Mutators
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_dept(string dept)
    {
        this->dept = dept;
    }

    void set_joining(Date joining)
    {
        this->joining = joining;
    }

    // Accept
    void accept()
    {
        cout << "Please Enter id : ";
        cin >> this->id;

        cout << "Please Enter sal : ";
        cin >> this->sal;

        cout << "Please Enter dept : ";
        cin >> this->dept;

        joining.accept();
    }

    // Display
    void display()
    {
        cout << "Id : " << this->id << endl;
        cout << "Sal : " << this->sal << endl;
        cout << "Dept : " << this->dept << endl;
        joining.display();
    }
};

// Person class
class Person
{
    // private data members
private:
    string name;
    string addr;
    Date birth_date;

    // member functions
public:
    // parameterless constructor // default = -99
    Person()
    {
        this->name = "-99";
        this->addr = "-99";
    }

    // parameterized construrtor
    Person(string name, string addr, int day, int month, int year) : birth_date(day, month, year)

    {
        this->name = name;
        this->addr = addr;
    }

    // Inspectors

    string get_name()
    {
        return this->name;
    }

    string get_addr()
    {
        return this->addr;
    }

    Date get_birth_date()
    {
        return this->birth_date;
    }

    // Mutators
    void set_name(string name)
    {
        this->name = name;
    }

    void set_addr(string addr)
    {
        this->addr = addr;
    }
    void set_birth_date(Date birth_date)
    {
        this->birth_date = birth_date;
    }

    // Accept
    void accept()
    {

        cout << "Please Enter name : ";
        cin >> this->name;

        cout << "Please Enter addr : ";
        cin >> this->addr;

        birth_date.accept();
    }

    // Display
    void display()
    {
        cout << "name : " << this->name << endl;
        cout << "addr : " << this->addr << endl;
        birth_date.display();
    }
};

int main()
{

    Employee e1;
    Employee e2(10, 2000, "dpt1", 20, 20, 2020);
    Person p1;
    Person p2("krit", "karad", 30, 30, 3030);
    e1.display();
    e2.display();
    p1.display();
    p2.display();
    e1.accept();
    e2.accept();
    p1.accept();
    p2.accept();
    e1.display();
    e2.display();
    p1.display();
    p2.display();

    return 0;
}