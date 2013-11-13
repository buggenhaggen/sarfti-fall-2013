#include <iostream>
#include <conio.h>

using namespace std;

class ClassA
{
 protected: 
 int a;
 friend int one_b(ClassA &);
 void two_b(int b)
 {
  a=b+b;
 };
 public:
 int one_a(void)
 {
  return a;
 };
 void two_a(int b)
 {
  a=b+b;
 };
};
 int one_b(ClassA &object)
 {
  return object.a;
 }
 int main(void)
 {
 ClassA x;
 int y=one_b(x);
 getch();
 return 0;
 }
