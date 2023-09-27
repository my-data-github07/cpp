#include<iostream>
using namespace std;
namespace NStudent
{

class student
{
private:
    int rollno;
    string name;
    double marks;

public:
void initStudent()
{
    this->rollno=0;
    this->name=" ";
    this->marks=0;
}
void printStudentOnConsole()
{
    cout<<"Student Details:"<<endl;
    cout<<"Roll No:"<<this->rollno<<endl;
    cout<<"Name:"<<this->name<<endl;
    cout<<"Marks:"<<this->marks<<endl;
}

void acceptStudentOnConsole()
{
    cout<<"Enter Roll No:";
    cin>>this->rollno;

    cout<<"Enter Syudent Name:";
    cin>>this->name;

    cout<<"Enter marks:";
    cin>>this->marks;
}
};
}

int menu()
{
    int choice;
    cout<<"-----------------------------------"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. INITSTUDENT"<<endl;
    cout<<"2. PRINT STUDENT ON CONSOLE"<<endl;
    cout<<"3. ACCEPT STUDENT FROM CONSOLE"<<endl;

    cin>>choice;
    return choice;
}
using namespace NStudent;
int main()
{
    int choice;
    class student s;
    
    while((choice =menu())!= 0)
    {
        switch (choice)
        {
            case 1:
            s.initStudent();
            break;

            case 2:
            s.printStudentOnConsole();
            break;

            case 3:
            s.acceptStudentOnConsole();
            break;

            default:
            cout<<"Wrong Choice........"<<endl;
            cout<<"Enter valid Choice........"<<endl;
            break;
        }
    }
cout<<"Thanks for using our APP.........";
return 0;
}