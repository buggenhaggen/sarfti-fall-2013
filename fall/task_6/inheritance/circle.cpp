//CIRCLE.CPP
//����������� �������-��������� ������ ����
#include "circle.h"
#include <iostream.h>
#include <iomanip.h>

//����������� ������ circle �������� �����������  point � ���������������� ���������, ����� ������ ��������� �������� �������
Circle::Circle(float r, float a, float b)
  :Point (a, b) //����� ������������ �������� ������
  { radius =r; }
  
  //��������� ������� �����
  void Circle::setRadius (float r) {radius = r;}
  
  //��������� ������� �����
  float Circle::getRadius() const {return radius;}
  
  //���������� ������� �����
  float Circle::area() const
  {return 3.14159*radius*radius; }
  
  //����� ������ ����� 
  ostream &operator << (ostream &output, const Circle &c)
  {
    output<<"����� = ["<<c.x<<", "<<c.y<<"]; ������ ="<<setiosflags(ios::showpoint)<<setprecision(2)<<c.radius;
    return output; //����������� ��������� �������
    }
