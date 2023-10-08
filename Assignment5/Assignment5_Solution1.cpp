#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
// Student management

// Student class
class Student
{
    // Some Data Members
private:
    string name;
    char gender;
    int rollNumber;
    double marksEnglish;
    double marksHindi;
    double marksMaths;
    static int length;

    // Member Functions
public:
    // initializing defaults in Parameterless constructer
    Student()
    {
        this->name = "default";
        this->rollNumber = 000;
        this->gender = 'N';
        this->marksEnglish = 0;
        this->marksHindi = 0;
        this->marksMaths = 0;
    }

    // Accepting values with Promt
    void acceptValues()
    {
        cout << "_________   INPUT _________" << endl;
        cout << "Please Enter the name : ";
        cin >> this->name;
        cout << "Please Enter the roll Number : ";
        cin >> this->rollNumber;
        cout << "Please Enter the gender('M'/'F'/'N') : ";
        cin >> this->gender;
        cout << "Please Enter the marks in English : ";
        cin >> this->marksEnglish;
        cout << "Please Enter the marks in Hindi : ";
        cin >> this->marksHindi;
        cout << "Please Enter the marks in Maths : ";
        cin >> this->marksMaths;
        cout << endl <<"_____SUCCESSFULLY ACCEPTED DETAILS_____ " << endl
             << endl;
        length++;
    }

    // Printing details of student
    void print()
    {
        cout << "_________ PRINT ________" << endl;
        cout << "Name : " << this->name << endl;
        cout << "Roll Number : " << this->rollNumber << endl;
        cout << "Gender ('M'/'F'/'N') : " << this->gender << endl;
        cout << "Percentage : " << (this->marksEnglish + this->marksHindi + this->marksMaths) / 3 << endl;
        cout << "----------------------------" << endl;
    }

    // Inspecter for Roll_Number for searching & sorting ;
    int getRoll()
    {
        return this->rollNumber;
    }

    // static function to get the count of students
    static int getLength()
    {
        return length;
    }
};
// initializing static variable
int Student::length = 0;

int menu()
{
    int flag;
    cout << "****************************************" << endl;
    cout << "WELCOME TO CPP - Student Management" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add a Student " << endl;
    cout << "2. Print all Students" << endl;
    cout << "3. Search a Student" << endl;
    cout << "4. Sort the array of Students" << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "****************************************" << endl;
    return flag;
}
//Searching a student on Roll-no ;
int searchRecords(Student arr[])
{
    int temp;
    cout << "Please tell the roll no of the target student : ";
    cin >> temp;
    for (int i = 0; i <= Student::getLength(); i++)
        if (arr[i].getRoll() == temp)
        {
            return i;
            break;
        }
    return -1;
}



//Sorting a student on Roll-no ;
void sortRecords(Student arr[])
{
    int n = Student::getLength();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (arr[i].getRoll() > arr[j].getRoll())
            {
                Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }

    cout << "YOUR ARRAY IS SORTED on Basis of Roll_No"<<endl;
}

int main()
{
    int n;
    int flag;
    cout << "Hello, how many students are there in your ORG :";
    cin >> n;
    Student arr[n];
    while ((flag = menu()) != 0)
    {
        int index = Student::getLength();
        switch (flag)
        {
        case 1:
            arr[index].acceptValues();
            index++;
            break;
        case 2:
            for (int i = 0; i < index; i++)
                arr[i].print();
            break;
        case 3:
            cout << searchRecords(arr);
            break;
        case 4:
            sortRecords(arr);
            break;

        default:
            cout << "Please Try Again :" << endl;
            break;
        }
    }
}