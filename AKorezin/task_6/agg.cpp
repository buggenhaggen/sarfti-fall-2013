#include <iostream>

using namespace std;

class A
{
public:
void setx(int x1){x=x1;};
A(void){x=1;};
int getx(void){return x;};
private:
int x;
};

class B
{
private:
int x;
public:
A agg;
void setx(int x1){x=x1;};
B(void){x=2;};
int getx(void){return x;};
};

int main(void)
{
B agg1;
cout << agg1.getx()<<" "<< agg1.agg.getx()<<endl;
agg1.setx(4);
agg1.agg.setx(3);
cout << agg1.getx()<<" "<< agg1.agg.getx()<<endl;
return 0;
}
