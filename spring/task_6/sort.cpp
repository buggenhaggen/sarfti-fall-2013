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
		for(int i = 0; i < n; ++i) // i - номер текущего шага
    { 
        int pos = i; 
        tmp = a[i];
        for(int j = i + 1; j < n; ++j) // цикл выбора наименьшего элемента
        {
            if (a[j] < tmp) 
           {
               pos = j; 
               tmp = a[j]; 
           }
        }
        a[pos] = a[i]; 
        a[i] = tmp; // меняем местами наименьший с a[i]
		if(n>1)
		{
			sort(int (n-1));//рекурсия-функция вызывает саму себя, если n>1
		}
    }    
   return;
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
