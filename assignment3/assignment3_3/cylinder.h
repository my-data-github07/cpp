#ifndef CYLINDER_H
#define CYLINDER_H

class cylinder
{
private:
    double radius;
    double height;
public:
    cylinder();
    cylinder(double radius, double height);
    double getRadius();
    void setRadius(double radius);
    double getHeight();
    void setHeight(double height);
    double getVolume();
    void printVolume();
};
#endif