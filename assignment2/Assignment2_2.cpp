#include<iostream>
using namespace std;

class address
{
    private:
    string building;
    string street;
    string city;
    int pin;

    public:

    address()
    {
        this->building=" ";
        this->street=" ";
        this->city=" ";
        this->pin=0;
    } 

    address(string building,string street,string city,int pin)
    {
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }

    void accept()
    {
        cout<<"Enter building name:";
        cin>>this->building;

        cout<<"Enter street name:";
        cin>>this->street;

        cout<<"Enter City name:";
        cin>>this->city;

        cout<<"Enter Pin No:";
        cin>>this->pin;
    }

    void display()
    {
        cout<<"****ADDRESS*****"<<endl;
        cout<<"Building name:"<<this->building<<endl;
        cout<<"street name:"<<this->street<<endl;
        cout<<"city name:"<<this->city<<endl;
        cout<<"pin name:"<<this->pin<<endl;
    }

    string get_building()
    {
        return this->building;
    }

    string get_street()
    {
        return this->street;
    }

    string get_city()
    {
        return this->city;
    }

    int get_pin()
    {
        return this->pin;
    }

    void set_building(string building)
    {
        this->building=building;
    }

    void set_street(string street)
    {
        this->street=street;
    }

    void set_city(string city)
    {
        this->city=city;
    }

    void set_pin(int pin)
    {
        this->pin=pin;
    }
};

int main()
{
    address a;
    a.accept();
    a.display();

    address a2("XYZ","MAIN_ROAD","KOLHAPUR",416100);
    a2.display();

    a.set_building("Matoshri");
    a.set_city("Mumbai");
    a.set_street("Choupati");
    a.set_pin(415109);

    cout<<"-----------------------";
    cout<<a.get_building()<<endl;
    cout<<a.get_city()<<endl;
    cout<<a.get_street()<<endl;
    cout<<a.get_pin()<<endl;
    return 0;
}