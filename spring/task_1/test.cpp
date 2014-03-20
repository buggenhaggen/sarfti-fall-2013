// Если стек не пуст-программа удаляет верхний элемент стека и выводит стек на экран. Если стек пуст- программа завершается
#include "conio.h"
#include "iostream"
#include "stack"

using namespace std;
class S
{
public:
	stack<int> original;//первый стек 
    stack<int> auxiliary;//второй вспомогательный стек
    
    int i;//первая переменная
    int m;//вторая переменная
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
			cout<<"cтек без верхнего элемента:  ";
			for(i=0;i<(x-1);i++) //переписываем стек, удалив предварительно верхний элемент("последний вошел-первый вышел")
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
	cout<<"Введите число элементов в стеке: ";
	int x;
	cin>>x;
	cout<<"\n";
	if(x!=0)
	{
	cout <<"стек: ";
	obj.set(x);
	}
	obj.p(x);        
    getch();
}