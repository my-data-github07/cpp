#include <iostream>
using namespace std;

// Employee class
class Employee
{
    // private data members
private:
    int id;
    float sal;

    // member functions
public:
    // parameterless constructor // default = -99
    Employee()
    {
        this->id = -99;

        this->sal = -99;
    }

    // parameterized construrtor
    Employee(int id, float sal)

    {
        this->id = id;
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

    // Mutators
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    void set_id(int id)
    {
        this->id = id;
    }

    // Accept
    void accept()
    {
        cout << "Please Enter id : ";
        cin >> this->id;

        cout << "Please Enter sal : ";
        cin >> this->sal;
    }

    // Display
    void display()
    {
        cout << "Id : " << this->id << endl;
        cout << "Sal : " << this->sal << endl;
    }
};

class Manager : virtual protected Employee
{
    // data members
private:
    float bonus;
    // member functions
public:
    // Parameterless constructor
    Manager()
    {
        this->bonus = -99;
    }

    // Parameterised constructor
    Manager(int id, float sal, float bonus) : Employee::Employee(id, sal)
    {
        this->bonus = bonus;
    }

    // Inspecters

    float get_bonus()
    {
        return this->bonus;
    }

    // Mutators
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }

    // Accept Function

    void accept()
    {
        Employee::accept();
        cout << "Please enter Bonus : ";
        cin >> this->bonus;
    }

    // Display Funtion

    void display()
    {
        Employee::display();
        cout << "Bonus :" << this->bonus << endl;
    }

    // Some protected Functions to maintain Abstraction
protected:
    void display_manager()
    {
        cout << "Bonus :" << this->bonus << endl;
    }

    void accept_manager()
    {
        cout << "Please enter Bonus : ";
        cin >> this->bonus;
    }
};

// SalesMan class
class Salesman : virtual protected Employee
{
    // data members
private:
    float comm;
    // member functions
public:
    // Parameterless constructor
    Salesman()
    {
        this->comm = -99;
    }

    // Parameterised constructor
    Salesman(int id, float sal, float comm) : Employee::Employee(id, sal)
    {
        this->comm = comm;
    }

    // Inspecters

    float get_comm()
    {
        return this->comm;
    }

    // Mutators
    void set_comm(float comm)
    {
        this->comm = comm;
    }

    // Accept Function

    void accept()
    {
        Employee::accept();
        cout << "Please enter comm : ";
        cin >> this->comm;
    }

    // Display Funtion

    void display()
    {
        Employee::display();
        cout << "comm :" << this->comm << endl;
    }

    // Some protected Functions to maintain Abstraction
protected:
    void display_salesman()
    {
        cout << "comm :" << this->comm << endl;
    }

    void accept_salesman()
    {
        cout << "Please enter comm : ";
        cin >> this->comm;
    }
};

// sales_manager Class

class Sales_manager : Manager, Salesman
{

public:
    // Member Functions
    Sales_manager()
    {
    }
    Sales_manager(int id, float sal, float bonus, float comm) : Employee(id, sal)
    {
        Manager::set_bonus(bonus);
        Salesman::set_comm(comm);
    }

    // Display function
    void display()
    {
        Employee::display();
        Manager::display_manager();
        Salesman::display_salesman();
    }

    // Accept function
    void accept()
    {
        Employee::accept();
        Manager::accept_manager();
        Salesman::display_salesman();
    }
};

int main()
{
    Sales_manager sm(1, 2000, 222, 333);
    sm.display();

    return 0;
}
