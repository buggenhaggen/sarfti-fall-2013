#include <iostream>
#include <conio.h>

using namespace std;

class Class_1 //внешний класс
{
private: //закрытые объекты( main "не видит")
int b;
Class_AGR *aggregated; //указатель на агрегируемый объект
public:
void one_B(int b1)
{
b=b1+1;
};

Class_1(Class_AGR *aggregated_1=NULL,int b1=5):aggregated(aggregated_1),b(b1);

int two_B(void)
{
return b;
};

int two_A(void)
{
return aggregated->two_A();
};

void one_A(int a1)
{
aggregated->one_A(a1);
};
};

class Class_AGR//агрегируемый класс
{
public:
void one_A(int a1)
{
a=a1+1;
};
Class_AGR(int a1=5):a(a1);
int two_A(void)
{
return a;
};
private: //закрытые объекты
int a;
};

int main(void)
{
Class_AGR *aggregated_1 = new Class_AGR();
Class_1 aggregated_2(aggregated_1);
cout « aggregated_2.two_B()«"/n"« aaggregated_2.two_A()«endl;
aggregated_2.one_A();
aggregated_2.one_B();
cout « aggregated_2.two_В()«"/n"« aaggregated_2.two_A()«endl;
delete aaggregated_1;
return 0;
getch();
}