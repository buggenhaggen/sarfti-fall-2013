//CIRCLE.H
//����������� ������ Circle
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream.h>
#include <iomanip.h>
#include "point.h"

clacc Circle:public Point     //Circle ��������� point
{
  friend ostream &operator<<(ostream &,  const Circle &);
public:
  //����������� �� ���������
  Circle(float r=0.0, float x=0, float y=0);
  
  void setRadius (float);//��������� �������
  float getRadius() const; //����������� �������
  float area() const;// ���������� �������
protected:
float radius; //������ �����
};
#endif
  