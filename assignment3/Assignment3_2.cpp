#include<iostream>
using namespace std;
class tollbooth{
private:
    unsigned int total_cars;
    double total_money;
public:
    tollbooth()
    {
    this->total_cars=0;
    this->total_money=0;
    }
    void payingcars()
    {
        total_cars++;
        total_money+=0.5;
    }
    void nopaycar()
    {
        total_cars++;
    }
    void printnConsole()
    {
        cout<<"Total Cars ="<<this->total_cars<<endl;
        cout<<"Total money paid ="<<this->total_money<<" cent"<<endl;
        cout<<"No of Paying Cars ="<<(this->total_money)/0.5<<endl;
        cout<<"No of non Paying Cars ="<<(this->total_cars)-(this->total_money)/0.5<<endl;
    }
};
int menu()
{
    int choice;
    cout<<"****************************"<<endl;

    cout<<"0.Exit"<<endl;
    cout<<"1.Car Pay"<<endl;
    cout<<"2.Car Not Pay"<<endl;
    cout<<"3.Print total on Console"<<endl;
    cout<<"Enter Your Choice = "<<endl;
    cin>>choice;
    cout<<"****************************"<<endl;

    return choice;

}
int main()
{
    tollbooth a;
    int choice;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:a.payingcars();
                    break;
            case 2:a.nopaycar();
                    break;
            case 3:a.printnConsole();
                    break;
            default:cout<<"Invalid Case..."<<endl;
                    break;
        }
    }
    return 0;
}