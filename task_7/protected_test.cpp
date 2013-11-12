#include <iostream>
#include <conio.h>

using namespace std;

class Class_1
  {
  protected: //защищенные данные
  int num1;
  friend int function1_num2(Class_1 &);//дружествен. ф.
  void function2_num2(int num2)//описание ф
  {
    num1=num2+num2*2;
   };
  public://публичные данные
   int function1_num1(void)
      {
        return num1;
      };
  void function2_num1(int num2)
  {
    num1=num2+num2*2;
   };
  };
  int function1_num2(Class_1 &object)
  {
    return object.num1;
  }
  int main(void)
  {
    Class_1 x;//создание объекта х, пренадлежащего классуClass_1
    int f=function1_num2(x);
    return 0;
    getch();
   }
