#include <iostream>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

void Out(stack<int> cur_stack)
{
	int i = 1;
	while(!cur_stack.empty())
	{
		cout<<i<<":\t"<<cur_stack.top()<<endl;
		cur_stack.pop();
		i++;
	}
}
stack<int> sort(stack<int> initial)
{
	stack<int> sorted;	
	while (!initial.empty())
	{	
		if (sorted.empty())//если сортированный стек пустой добавляем в него верхний элемент исходного стека
		{
			sorted.push(initial.top());
			initial.pop();
		}
		else
		{
			if (initial.top() <= sorted.top())//если верхний эл-т отсортированного стека >=  верхнего элемент исходного стека добавляем в него верхний элемент исходного стека
			{
				sorted.push(initial.top());
				initial.pop();
			}
			else//иначе сохраняем значение верхнего эл-та исходного стека в переменную и перемещаем из отсортированного эл-ты пока верхний эл-т отсортированного стека не будет >= сохраненного значения
			{
				int ini_top = initial.top();
				initial.pop();
				while(ini_top > sorted.top())//сравниваем верхний элемент изначального стека с верхним отсортированного 
				{
					initial.push(sorted.top());
					sorted.pop();
					if(sorted.empty())//выходим из цикла если отсортированный стек пуст
						break;
				}
				sorted.push(ini_top);
			}
		}		
	}
	return sorted;
}
int main()
{
	//устанавливаем поддержку русских шрифтов
	setlocale(LC_ALL, "Russian");
	stack<int> initial, sorted;
	int n;
	cout<<"Введите количество эл-ов стека: ";
	cin>>n;
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	for (int  i = 0; i < n; i++ )
	{
		//заполним исходный стек случайными значениями из диапозона [-1000; 1000] 
		initial.push((double)rand() / (RAND_MAX + 1) * (1000 - (-1000))	+ (-1000));		
	}
	cout<<"Исходный стек:"<<endl;
	Out(initial);
	sorted = sort(initial);
	cout<<"Отсортированный стек:"<<endl;
	Out(sorted);	
	return 0;
}