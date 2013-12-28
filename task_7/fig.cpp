//FIG.CPP
//circle a?aeaa? eeanna

#include "circle.h"
#include <iostream>
#include <iomanip>
#include "point.h"
#include <conio.h>
using namespace std;

main()
{
  Circle c(2.5, 3.7, 4.3);
  cout<<"The x coordinate is "<<c.getX()<<endl<<"Y-coordinate is "<<c.getY()<<endl<<"Radius is "<<c.getRadius();
  
  c.setRadius(4.25);
  c.setPoint(2, 2);
  cout<<setiosflags(ios::fixed | ios::showpoint);
  cout<<endl<<endl<<"The new coordinates of the point and a radius equal  "<<endl<<c<<endl<<"The area "<<c.area()<<endl;
  Point &pRef=c;
  cout<<endl<<"Printing circle as point"<<pRef<<endl;
 
  
  return 0;
  }