
#include <iostream>
#include <conio.h>
#define N 7

using namespace std;
 
class S
{ 
public:
	int n;
	int a[7];
	int tmp;
	int j;
	int i;
	void set(int n)//заполнение случайными числами
	{
		for(int i=0; i<n; i++)
		{
			a[i]=0+rand()%100;
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	};
	
	void sort( int n)//сортировка и печать
	{
		for(int i=1; i<n; i++)
		{
			for(int j=i; j>0&&a[j-1]>a[j]; j--)
			{
				swap(a[j-1],a[j]);
			}
		}		
	};

	void print(int n)//печать на экран отсортированного массива
	{ 
		for(int k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
	};



};
int main()
{
	int n=7;
	S obj;
	obj.set(n);
	obj.sort(n);
	obj.print(n);
	getch();
}
