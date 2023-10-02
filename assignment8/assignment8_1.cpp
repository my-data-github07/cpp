#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance()
    {

        this->feet = 0;
        this->inches = 0;
    }
    Distance(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    void acceptDistance()
    {
        cout << "Enter the Feet " << endl;
        cin >> this->feet;
        cout << "Enter the Inches " << endl;
        cin >> this->inches;
    }
    int getFeet()
    {
        return this->feet;
    }
    int getInches()
    {
        return this->inches;
    }
    void setFeet()
    {
        cout << "Enter Feet: " << endl;

        cin >> this->feet;
    }
    void setInches()
    {
        cout << "Enter Inches: " << endl;
        cin >> this->inches;
    }
    void displayDistance()
    {
        cout << "The Feet: " << this->feet << endl;
        cout << "The Inches " << this->inches << endl;
    }
    Distance operator+(Distance &other)
    {
        Distance d;
        d.feet = this->feet + other.feet;
        d.inches = this->inches + other.inches;
        if (inches > 11)
        {
            d.feet += d.inches / 12;
            d.inches = d.inches % 12;
        }
        return d;
    }
    void operator++()
    {

        this->inches++;
        if (this->inches > 11)
        {
            this->feet++;
            this->inches = 0;
        }
    }

    friend Distance operator--(Distance &dist);
    friend bool operator==(Distance &d, Distance &dist);
};
bool operator==(Distance &d, Distance &dist)
{
    if (d.feet == dist.inches && d.inches == dist.inches)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Distance operator--(Distance &dist)
{
    dist.inches--;
    if (dist.inches < 0)
    {
        dist.inches = 11;
        dist.feet--;
    }
    return dist;
}

void operator<<(ostream &out, Distance &dist)
{
    out << "Feet :" << dist.getFeet() << endl;
    out << "Inches :" << dist.getInches() << endl;
}
void operator>>(istream &in, Distance &dist)
{
    dist.setFeet();
    dist.setInches();
}
int main()
{
    Distance d1, d2;
    cin >> d1;
    cin >> d2;
    cout << "--------------------------------" << endl;
    cout << d1;
    cout << "--------------------------------" << endl;
    cout << d2;
    cout << "--------------------------------" << endl;
   Distance d3 = d1 + d2;
    cout << d3;
    cout << "--------------------------------" << endl;
    ++d1;
    --d2;
    cout << d1;
    cout << d2;
    cout << "--------------------------------" << endl;
    return 0;
}