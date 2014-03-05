//FIG.CPP
//circle драйвер класса

#include "circle.h"
#include <iostream.h>
#include <iomanip.h>
#include "point.h"

main()
{
  Circle c(2.5, 3.7, 4.3);
  cout<<"координата х равна "<<c.getX()<<endl<<"Координата у равна "<<c.getY()<<endl<<"радиус равен "<<c.getRadius();
  
  c.setRadius(4.25);
  c.setPoint(2, 2);
  cout<<setiosflags(ios::fixed | ios::showpoint);
  cout<<endl<<endl<<"новые координаты точки и радиус равны "<<endl<<c<<endl<<"площадь равна "<<c.area()<<endl;
  
  Point &pRef=c;
  cout<<endl<<"печать circle как point"<<pRef<<endl;
  
  return 0:
  }