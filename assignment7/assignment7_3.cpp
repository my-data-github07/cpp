#include <iostream>
using namespace std;
class Employee
{
private:
    int id;
    float salary;

protected:
    int getId()
    {
        return this->id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getSal()
    {
        return this->salary;
    }
    void setId(float salary)
    {
        this->salary = salary;
    }

public:
    Employee()
    {
        this->id = 0;
        this->salary = 0;
    }
    Employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }
    virtual void display()
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Employee Id : " << this->id << endl;
        cout << "Employee Salary : " << this->salary << endl;
    }
    virtual void accept()
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Enter Employee id : ";
        cin >> this->id;
        cout << "Enter Employee Salary : ";
        cin >> this->salary;
    }
};
class Manager : virtual public Employee
{
private:
    float bonus;

protected:
    void display_manager()
    {
        cout << "Bonus : " << this->bonus << endl;
    }
    void accept_Manager()
    {
        cout << "Enter Bonus : ";
        cin >> this->bonus;
    }
    float getBonus()
    {
        return this->bonus;
    }
    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }

public:
    Manager()
    {
        this->bonus = 0;
    }
    Manager(float bonus, int id, float sal) : Employee(id, sal)
    {
        this->bonus = bonus;
    }
    void display()
    {
        Employee::display();
        display_manager();
    }
    void accept()
    {
        Employee::accept();
        accept_Manager();
    }
};
class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void display_Salesman()
    {
        cout << "Employee Commission : " << this->comm << endl;
    }
    void accept_Salesman()
    {
        cout << "Enter Employee Commission : ";
        cin >> this->comm;
    }
    float getComm()
    {
        return this->comm;
    }
    void setComm(float comm)
    {
        this->comm = comm;
    }

public:
    Salesman()
    {
        this->comm = 0;
    }
    Salesman(float comm, int id, float sal) : Employee(id, sal)
    {
        this->comm = comm;
    }
    void display()
    {
        Employee::display();
        display_Salesman();
    }
    void accept()
    {
        Employee::accept();
        accept_Salesman();
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int id, float sal, float comm, float bonus) : Manager(bonus, id, sal)
    {
    }
    void display()
    {
        Employee::display();
        display_manager();
        display_Salesman();
    }
    void accept()
    {
        Employee::accept();
        accept_Manager();
        accept_Salesman();
    }
};

int menu()
{
    int choice;
    cout << "--------------------------------------------------------" << endl;
    cout << "1. Accept Employee" << endl;
    cout << "2. Display the count of all employees with respect to designation " << endl;
    cout << "3. Display All Managers" << endl;
    cout << "4. Display All Salesman" << endl;
    cout << "5. Display All SalesManager" << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << "--------------------------------------------------------" << endl;
    return choice;
}

int main()
{
    Employee *e1[5];
    int choice;
    int index = 0;
    int count;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "--------------------------------------------------------" << endl;
            cout << "Select Department" << endl;
            cout << "1. Manager" << endl;
            cout << "2. Salesman" << endl;
            cout << "3. SalesManager" << endl;
            cout << "Enter Your Choice" << endl;
            cout << "--------------------------------------------------------" << endl;
            cin >> choice;
            if (choice == 1)
            {
                if (index < 10)
                {
                    e1[index] = new Manager;
                    Manager *manager = dynamic_cast<Manager *>(e1[index]);
                    manager->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
            }
            else if (choice == 2)
            {
                if (index < 10)
                {
                    e1[index] = new Salesman;
                    Salesman *salesman = dynamic_cast<Salesman *>(e1[index]);
                    salesman->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
            }
            else
            {
                if (index < 10)
                {
                    e1[index] = new SalesManager;
                    SalesManager *salesManager = dynamic_cast<SalesManager *>(e1[index]);
                    salesManager->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full" << endl;
                }
            }
            break;
        case 2:
            count = 0;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(Manager))
                {
                    count++;
                }
            }
            cout << "No of Manager : " << count << endl;
            count = 0;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(Salesman))
                {
                    count++;
                }
            }
            cout << "No of Salesman : " << count << endl;
            count = 0;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(SalesManager))
                {
                    count++;
                }
            }
            cout << "No of SalesManager : " << count << endl;
            break;
        case 3:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(Manager))
                {
                    e1[i]->display();
                }
            }
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(Salesman))
                {
                    e1[i]->display();
                }
            }
            break;
        case 5:
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e1[i]) == typeid(SalesManager))
                {
                    e1[i]->display();
                }
            }
            break;
        }
    }
    delete[] *e1;
    return 0;
}