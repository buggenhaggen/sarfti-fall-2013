//POINT.H
//Определение класса Point
#ifndef POINT_H
#define POINT_H

class Point
  {
    friend ostream &operator<<(ostream &, const Point &);
  public:
     Point(float=0, float=0);
     void setPoint(float, float);
     float getX() const { return x; }
     float getY() const { return y; }
  protected://доступно производным классам
    float x, y;//координаты point
    };
#endif