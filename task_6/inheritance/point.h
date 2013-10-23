//POINT.H
//Определение класса Point
#ifndef POINT_H
#define POINT_H

class Point
  {
    friend ostream &operator<<(ostream &, const Point &);
  public:
     Point(float=0, float=0);//конструктор по умолчанию
     void setPoint(float, float);//установка координат
     float getX() const { return x; }//получение координаты х
     float getY() const { return y; }//получение координаты у
  protected://доступно производным классам
    float x, y;//координаты point
    };
#endif