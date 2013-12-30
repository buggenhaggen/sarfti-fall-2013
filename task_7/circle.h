
//CIRCLE.H

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <iomanip>
#include "point.h"

using namespace std;

class Circle:public Point   
{
  friend ostream &operator<<(ostream &,  const Circle &);
public:
  
  Circle(double r=0.0, double x=0, double y=0);
  
  void setRadius (double);
  double getRadius() const; 
  double area() const;
protected:
double radius; 
};
#endif