// Если стек не пуст-программа удаляет верхний элемент стека и выводит оставшиеся на экран. Если стек пуст, то после вызова функции void p(int x)  программа завершается
#include "conio.h"
#include "iostream"
#include "stack"

using namespace std;
class S
{
public:
	stack<int> original;
 
    
    int i;
    int m;
	void set(int x)
	{
		for(i=0;i<x;i++) 
		{
          original.push(rand()%100);
          cout << original.top() << " ";
		}
 
    cout <<"\n";
	};
	void p(int x)
	{
		original.pop();

		if(x!=0)
		{
			cout<<"стек без верхнего элемента: ";
			for(i=0;i<(x-1);i++) 
				{
					int m=original.top();
					cout<<m<<" ";
					original.pop();
				}
		}
	};
};

int main()
{
    setlocale(LC_ALL,"Russian");
	S obj;
	cout<<"Введите количество элементов в стеке ";
	int x;
	cin>>x;
	cout<<"\n";
	if(x!=0)
	{
	cout <<"стек  ";
	obj.set(x);
	}
	obj.p(x);        
    getch();
}
