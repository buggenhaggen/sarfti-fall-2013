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
		for(i=0;i<x;i++) //заполняем первый стек случайными значениями
		{
          original.push(rand()%100);
          cout << original.top() << " ";//выводим значение самого верхнего элемента
		}
 
    cout <<"\n";
	};
	void sort(int x)
	{
		for(i=0;i<x;i++)
		{
			m=original.top();//присваиваем m значение верхнего элемента
			original.pop();//удаляем его из стека
			while(!original.empty())//пока первый стек не закончен
			{
				if(m<=original.top())
				{
					auxiliary.push(m);//если m меньше следующего элемента стека, добавляем его к вспомогательному стеку
					m=original.top();
					original.pop();
				}
				else//если m больше...
				{
					auxiliary.push(original.top());
					original.pop();
				}
			}
			original.push(m);
			while(!auxiliary.empty())//пока не закончен вспомогательный стек
			{
				original.push(auxiliary.top());//переписываем значения в исходный
				auxiliary.pop();
			}
		}
		while(!original.empty()) 
		{
			cout << original.top() << " ";
			original.pop();
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
		if(x<=0)
		{
			cout<<"число должно быть больше нуля \n";
		}
		else
		{
		cout<<"\n";
		cout <<"Первый стек: ";
		obj.set(x);
		cout << "Результат сортировки стека: ";//вывод результата
		obj.sort(x);
		}
		 getch();
		 return 0;

	}