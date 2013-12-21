//FIG.CPP
//circle a?aeaa? eeanna

#include "circle.h"
#include <iostream.h>
#include <iomanip.h>
#include "point.h"

main()
{
  Circle c(2.5, 3.7, 4.3);
  cout<<"eii?aeiaoa o ?aaia "<<c.getX()<<endl<<"Eii?aeiaoa o ?aaia "<<c.getY()<<endl<<"?aaeon ?aaai "<<c.getRadius();
  
  c.setRadius(4.25);
  c.setPoint(2, 2);
  cout<<setiosflags(ios::fixed | ios::showpoint);
  cout<<endl<<endl<<"iiaua eii?aeiaou oi?ee e ?aaeon ?aaiu "<<endl<<c<<endl<<"ieiuaau ?aaia "<<c.area()<<endl;
  
  Point &pRef=c;
  cout<<endl<<"ia?aou circle eae point"<<pRef<<endl;
  
  return 0:
  }