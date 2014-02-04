#include <iostream>
using namespace std;
class Parent
{
private:
int x;
public:
Parent(void)
{
x=1;
};
void setx(int x1)
{
x=x1;
};
int getx(void)
{
return x;
};
};
class Child:public Parent
{
private:
int y;
public:
Child(void)
{
y=1;
};
void sety(int y1)
{
y=y1;
};
void setxy(int x1, int y1)
{
setx(x1);
y=y1;
};
int gety(void)
{
return y;
};
};
int main(void)
{
Child obj;
cout<<obj.getx()<<" "<<obj.gety()<<endl;
obj.setx(1);
obj.sety(1);
cout<<obj.getx()<<" "<<obj.gety()<<endl;
obj.setxy(2,2);
cout<<obj.getx()<<" "<<obj.gety()<<endl;
return 0;
}