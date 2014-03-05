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
  //конструктор по умолчанию
  Circle(float r=0.0, float x=0, float y=0);
  
  void setRadius (float);//установка радиуса
  float getRadius() const; //возвращение радиуса
  float area() const;// вычисление площади
protected:
float radius; //радиус круга
};
#endif
  