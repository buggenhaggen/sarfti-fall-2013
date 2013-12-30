//POINT.H

#ifndef POINT_H
#define POINT_H
using namespace std;

class Point
  {
    friend ostream &operator<<(ostream &, const Point &);
  public:
     Point(double=0, double=0);
     void setPoint(double, double);
     double getX() const { return x; }
     double getY() const { return y; }
  protected:
    double x, y;
    };
#endif