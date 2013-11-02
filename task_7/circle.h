//CIRCLE.H
//определение класса Circle
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream.h>
#include <iomanip.h>
#include "point.h"

clacc Circle:public Point     //Circle наследует point
{
  friend ostream &operator<<(ostream &,  const Circle &);
public:
  
  Circle(float r=0.0);
  
  void setRadius (float);
  float getRadius() const; 
  float area() const;
  x=0; y=0;//protected-данные из родительского класса point
protected:
float radius; 
};
#endif
  