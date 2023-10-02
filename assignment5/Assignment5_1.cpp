#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no;
    string name;
    string gender;
    int mark1, mark2, mark3;

public:
    Student()
    {
        this->roll_no = 0;
        this->name = "";
        this->gender = "";
        this->mark1 = 0;
        this->mark2 = 0;
        this->mark3 = 0;
    }
    Student(int roll_no, string name, string gender, int mark1, int mark2, int mark3)
    {
        this->roll_no = roll_no;
        this->name = name;
        this->gender = gender;
        this->mark1 = mark1;
        this->mark2 = mark2;
        this->mark3 = mark3;
    }
    void accept()
    {
        cout << "Please enter your roll num:" << endl;
        cin >> this->roll_no;
        cout << "Please enter name:" << endl;
        cin >> this->name;
        cout << "Please enter Gender(M/F):" << endl;
        cin >> this->gender;
        cout << "Please enter marks of subject 1" << endl;
        cin >> this->mark1;
        cout << "Please enter marks of subject 2" << endl;
        cin >> this->mark2;
        cout << "Please enter marks of subject 3:" << endl;
        cin >> this->mark3;
    }
    double percetage()
    {
        return (((mark1 + mark2 + mark3) / 3));
    }
    void print()
    {
        cout << "Roll Num : " << this->roll_no << endl;
        cout << "Name is: " << this->name << endl;
        cout << "Gender is: " << this->gender << endl;
        cout << "percentage is: " << this->percetage() << endl;
    }
    int getRoll_no()
    {
        return this->roll_no;
    }
};
void sortRecords(Student arr[], int size, int index)
{
    for (int step = 0; step < size - 1; step++)
    {

        for (int i = 0; i < size - step - 1; i++)
        {

            if (arr[i].getRoll_no() > arr[i + 1].getRoll_no())
            {
                Student temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        arr[i].print();
    }
}
int searchRocords(Student arr[], int roll_no, int size)
{
    for (int i = 0; i <= size; i++)
    {

        if (arr[i].getRoll_no() == roll_no)
            return i;
    }
    return -1;
};
int menu()
{

    int ch;
    cout << "0. Exit " << endl;
    cout << "1. Accept Data" << endl;
    cout << "2. Sort Data" << endl;
    cout << "3. Search for record" << endl;
    cout << "4. print Data" << endl;
    cout << "Enter your choice : " << endl;
    cin >> ch;
    return ch;
}
int main()
{
    Student arr[5];
    int choice = 0;
    int index = 0;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            arr[index].accept();
            index++;
            break;
        }
        case 2:
        {
            sortRecords(arr, index, index);
            break;
        }
        case 3:
        {
            int roll_no;
            cout << "Enter roll no to search for records" << endl;
            cin >> roll_no;
            int status = searchRocords(arr, roll_no, index);
            if (status == -1)
            {
                cout << "element  not found !!" << endl;
            }
            else
            {
                arr[status].print();
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < index; i++)
            {
                arr[i].print();
            }
            break;
        }
        default:
        {
            printf("Wrong choice");
            break;
        }
        }
    }
    return 0;

}