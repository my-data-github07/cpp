#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;


void initDate()
{
    this->day =0;
    this->month=0;
    this->year=0000;
}

void printDateonConsole()
{
    cout<<"Date-"<<this->day<<":"<<this->month<<":"<<this->year<<endl;
}

void acceptDateFromConsole()
{
    cout<<"Enter a day:"<<endl;
    cin>>this->day;

    cout<<"Enter a month:"<<endl;
    cin>>this->month;

    cout<<"Enter a year:"<<endl;
    cin>>this->year;
}

bool isLeapyear()
{
    if(this->year % 4 == 0)
    return true;
    else
    return false; 
}
};

int menu()
{
    int choice;
    cout<<"*************************************"<<endl;;
    cout<<"0. EXIT"<<endl;
    cout<<"1. INITDATE"<<endl;
    cout<<"2. PRINT DATE ON CONSOLE"<<endl;
    cout<<"3. ACCEPT DATE FROM CONSOLE"<<endl;
    cout<<"4. Check your leap year"<<endl;
    cout<<"*************************************"<<endl;

    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    struct Date d1;

    while((choice=menu()) != 0)
    {
        switch(choice)
        {
            case 1:
            d1.initDate();
            break;

            case 2:
            d1.printDateonConsole();
            break;

            case 3:
            d1.acceptDateFromConsole();
            break;

            case 4:
            if(d1.isLeapyear())
            cout<<"These year is Leap Year..."<<endl;
            else
            cout<<"These year is not Leap Year..."<<endl; 
            break;

            default:
            cout<<"Enter valid Choice:"<<endl;
            break;
        }
    }
    cout<<"Thanks for using our App.....";
    return 0;
}