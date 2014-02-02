#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;
class A
{
protected:
  int x;
public:
A(void){x=1;};
};

class B:public A
{
public:
  int print_x(void){return x+20;}
};

int main(void)
{
B obj;
cout<<endl<<"print protected-data x+20: ";
cout<<obj.print_x()<<" ";
getch();
return 0;
}