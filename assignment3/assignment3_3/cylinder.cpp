#include "./cylinder.h"
#include<iostream>
using namespace std;

cylinder::cylinder():radius(radius=0),height(height=0)
{}
cylinder::cylinder(double radius, double height)
{
    this->radius=radius;
    this->height=height;
}
double cylinder::getRadius()
{
    return this->radius;
}
void cylinder::setRadius(double radius)
{
    this->radius=radius;
}
double cylinder::getHeight()
{
    return this->height;
}
void cylinder::setHeight(double height)
{
    this->height=height;
}
double cylinder::getVolume()
{
    // int volume=0;
    return 3.14*radius*radius*height;
    
}
void cylinder::printVolume(){
    cout<<"Volume of a cylinder ="<<this->getVolume()<<endl;
}