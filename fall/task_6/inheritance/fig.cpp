//FIG.CPP
//circle ������� ������

#include "circle.h"
#include <iostream.h>
#include <iomanip.h>
#include "point.h"

main()
{
  Circle c(2.5, 3.7, 4.3);
  cout<<"���������� � ����� "<<c.getX()<<endl<<"���������� � ����� "<<c.getY()<<endl<<"������ ����� "<<c.getRadius();
  
  c.setRadius(4.25);
  c.setPoint(2, 2);
  cout<<setiosflags(ios::fixed | ios::showpoint);
  cout<<endl<<endl<<"����� ���������� ����� � ������ ����� "<<endl<<c<<endl<<"������� ����� "<<c.area()<<endl;
  
  Point &pRef=c;
  cout<<endl<<"������ circle ��� point"<<pRef<<endl;
  
  return 0:
  }