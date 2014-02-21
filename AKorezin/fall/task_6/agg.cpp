#include <iostream>

using namespace std;

class A
{
public:
void setx(int x1){x=x1;};
A(int x1=1):x(x1){};
int getx(void){return x;};
private:
int x;
};

class B
{
private:
int y;
A *agg;
public:
void sety(int y1){y=y1;};
B(A *agg1=NULL,int y1=1):agg(agg1),y(y1){};
int gety(void){return y;};
int getx(void){return agg->getx();};
void setx(int x1){agg->setx(x1);};
};

int main(void)
{
A *agg1 = new A(2);
B agg2(agg1,2);
cout << agg2.gety()<<" "<< agg2.getx()<<endl;
agg2.setx(3);
agg2.sety(3);
cout << agg2.gety()<<" "<< agg2.getx()<<endl;
delete agg1;
return 0;
}
