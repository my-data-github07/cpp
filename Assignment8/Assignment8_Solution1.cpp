#include <iostream>
using namespace std;
class Distance
{
private:
    float feet;
    float inches;

public:
    Distance()
    {
        this->feet = 0;
        this->inches = 0;
    }
    Distance(float feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }

    Distance operator+(Distance d1)
    {
        Distance res;
        res.feet = d1.feet + this->feet;
        res.inches = d1.inches + this->inches;
        if (res.inches > 12)
        {
            res.feet = res.feet + 1;
            res.inches = res.inches - 12;
        }
        return res;
    }
    void operator++()
    {
        if (this->inches == 11)
        {
            this->feet = this->feet + 1;
            this->inches = 0;
        }
        else
        {
            this->inches = this->inches + 1;
        }
    }

    friend bool operator==(Distance &d1, Distance &d2);
    friend void operator--(Distance &d);
    friend void operator<<(ostream &ab, Distance &d);
    friend void operator>>(istream &ab, Distance &d);
};

bool operator==(Distance &d1, Distance &d2)
{
    return d1.feet == d2.feet && d1.inches == d2.inches;
}

void operator--(Distance &d)
{
    if (d.inches == 0)
    {
        d.feet = d.feet - 1;
        d.inches = 11;
    }
    else
    {
        d.inches = d.inches - 1;
    }
    if (d.feet < 0)
    {
        d.feet = 0;
        d.inches = 0;
    }
}

void operator<<(ostream &ab, Distance &d)
{
    ab << "Distance is feet : " << d.feet << " and " << d.inches << " inches " << endl;
}

void operator>>(istream &ab, Distance &d)
{
    cout << "Enter feet : ";
    ab >> d.feet;
    cout << "Enter inches : ";
    ab >> d.inches;
}

int main()
{

    Distance d1(4, 5);
    Distance d2(4, 5);

    if (d1 == d2)
    {
        cout << "Equal working" << endl;
        cout << "Test >> :" << endl;
        cin >> d1;
    }
    cout << d1;

    ++d1;

    cout << d1;
    --d1;
    cout << d1;
    Distance d3;
    d3 = d1 + d2;
    cout << d3;

    return 0;
}