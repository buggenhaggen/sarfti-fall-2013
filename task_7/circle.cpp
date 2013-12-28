//CIRCLE.CPP
//определение функций-элементов класса круг
#include "circle.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//конструктор класса circle вызывает конструктор  point с инициализаторами элементов, затем задает начальное значение радиуса
Circle::Circle(double r, double a, double b)
  :Point (a, b) //вызов конструктора базового класса
  { radius =r; }
  
  //установка радиуса круга
  void Circle::setRadius (double r) {radius = r;}
  
  //получение радиуса круга
  double Circle::getRadius() const {return radius;}
  
  //вычисление площади круга
  double Circle::area() const
  {return 3.14*radius*radius; }
  
  //вывод данных круга(переменные x, y относятся к protected-данным от наследуемого класса point(см point.h)
  ostream &operator << (ostream &output, const Circle &c)
  {
    output<<"Center = ["<<c.x<<", "<<c.y<<"]; Radius ="<<setiosflags(ios::showpoint)<<setprecision(2)<<c.radius;
    return output; //возможность сцепления вызовов
    }