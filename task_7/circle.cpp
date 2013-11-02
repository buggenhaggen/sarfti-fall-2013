//CIRCLE.CPP
//определение функций-элементов класса круг
#include "circle.h"
#include <iostream.h>
#include <iomanip.h>

//конструктор класса circle вызывает конструктор  point с инициализаторами элементов, затем задает начальное значение радиуса
Circle::Circle(float r, float a, float b)
  :Point (a, b) //вызов конструктора базового класса
  { radius =r; }
  
  //установка радиуса круга
  void Circle::setRadius (float r) {radius = r;}
  
  //получение радиуса круга
  float Circle::getRadius() const {return radius;}
  
  //вычисление площади круга
  float Circle::area() const
  {return 3.14159*radius*radius; }
  
  //вывод данных круга 
  ostream &operator << (ostream &output, const Circle &c)
  {
    output<<"Центр = ["<<c.x<<", "<<c.y<<"]; Радиус ="<<setiosflags(ios::showpoint)<<setprecision(2)<<c.radius;
    return output; //возможность сцепления вызовов
    }
