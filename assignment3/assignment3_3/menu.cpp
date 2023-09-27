#include<iostream>
using namespace std;
int menu()
{
    int choice;
    cout<<"--------------------------------"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"1.Set Radius "<<endl;
    cout<<"2.Get Radius "<<endl;
    cout<<"3.Set Height "<<endl;
    cout<<"4.Get Height "<<endl;
    cout<<"5.Get Volume of Cylinder "<<endl;
    cout<<"Enter Your Choice = ";
    cin>>choice;
    cout<<"--------------------------------"<<endl;
    return choice;
}