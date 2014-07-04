#include <iostream>
#include <stack>
#include <time.h>

using namespace std;
stack<int> SortStack(stack<int> initial);
int main()
{
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	//устанавливаем поддержку русских шрифтов
	setlocale(LC_ALL, "Russian");
	stack<int> initial;
	int count;
	cout<<"Задайте количество элементов стека: ";
	cin>>count;	
	cout<<"Исходный стек"<<endl;
	int i = 0;
	while(i < count)
	{
	//заполнем стек случайными числами от 0 до 100
		int value = rand()%100;
		cout<<value<<" ";
		initial.push(value);
		i++;
	}
	initial = SortStack(initial);
	cout<<endl;
	cout<<"Отсортированный стек"<<endl;
	while(!initial.empty())
	{
		cout<<initial.top()<<" ";
		initial.pop();	
	}	
	cout<<endl;
	return 0;
}
//функция сортировки
stack<int> SortStack(stack<int> initial)
{
	stack<int> sort;
	while (!initial.empty())
	{	
		if (sort.empty())//если сортированный стек пустой кидаем в него верхний элемент изнчального стека
		{
			sort.push(initial.top());
			initial.pop();
		}
		else
		{
			if (initial.top() <= sort.top())//если верхний эл-т отсортированного стека >=  верхнего элемент исходного стека добавляем в него верхний элемент исходного стека
			{
				sort.push(initial.top());
				initial.pop();
			}
			else//сохраняем значение верхнего эл-та исходного стека в переменную и перемещаем из отсортированного эл-ты пока верхний эл-т отсортированного стека не будет >= сохраненного значения
			{
				int ini_top = initial.top();
				initial.pop();
				while(ini_top > sort.top())
				{
					initial.push(sort.top());
					sort.pop();
					if(sort.empty())//выходим из цикла если отсортированный стек пуст
						break;
				}
				sort.push(ini_top);
			}
		}		
	}	
	return sort;
}