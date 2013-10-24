#include <iostream>
using namespace std;
class A
{
private:
int x;
public:
A(void){x=1;};
void setx(int x1){x=x1;};
int getx(void){return x;};
};
class B:public A
{
private:
int y;
public:
B(void){y=1;};
void sety(int y1){y=y1;};
void setxy(int x1, int y1){setx(x1);y=y1;};
int gety(void){return y;};
};
int main(void)
{
B inh;
cout<<inh.getx()<<" "<<inh.gety()<<endl;
inh.setx(2);
inh.sety(2);
cout<<inh.getx()<<" "<<inh.gety()<<endl;
inh.setxy(3,3);
cout<<inh.getx()<<" "<<inh.gety()<<endl;
return 0;
}
