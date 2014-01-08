#include <iostream>
#include <math.h>
#include <conio.h>


using namespace std;
class Parent
{
protected:
	int x;
public:
	
	Parent(void)
	{
	  x=1;
	};
	
	void setx(int x1)
	{
	  x=x1+3;
	};
	
	int getx(void)
	{
	  return x;
	};
};
class Child:public Parent
{
public:
	int print_x(void)
	{
	  return x;
	}
};

	int main(void)
{
	
	Child obj;
	cout<<"enter size of array: "<<endl;
	int size;
	cin>>size;
	for(int i=0; i<size; i++)
	{
	 obj.setx(i);
	 cout<<obj.getx()<<" ";
	}
	cout<<endl<<"print protected-data x: ";
	cout<<obj.print_x()<<" ";
	getch();
	return 0;
}
