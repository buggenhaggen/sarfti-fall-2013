#include <iostream>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

int main()
{
	//устанавливаем поддержку русских шрифтов
	setlocale(LC_ALL, "Russian");
	stack<int> base, sorted;
	int n;
	cout<<"Введите количество эл-ов стека: ";
	cin>>n;
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	cout<<"Исходный стек:"<<endl;
	for (int  i = 0; i < n; i++ )
	{
		//заполним исходный стек случайными значениями из диапозона [0; 100] 
		int value = (double)rand() / (RAND_MAX + 1) * 100;
		cout<<value<<"; ";
		base.push(value);		
	}
	cout<<endl;
	while (!base.empty())
	{	
		if (sorted.empty())//если сортированный стек пустой добавляем в него верхний элемент исходного стека
		{
			sorted.push(base.top());
			base.pop();
		}
		else
		{
			if (base.top() <= sorted.top())//если верхний эл-т отсортированного стека >=  верхнего элемент исходного стека добавляем в него верхний элемент исходного стека
			{
				sorted.push(base.top());
				base.pop();
			}
			else//иначе сохраняем значение верхнего эл-та исходного стека в переменную и перемещаем из отсортированного эл-ты пока верхний эл-т отсортированного стека не будет >= сохраненного значения
			{
				int ini_top = base.top();
				base.pop();
				while(ini_top > sorted.top())//сравниваем верхний элемент изначального стека с верхним отсортированного 
				{
					base.push(sorted.top());
					sorted.pop();
					if(sorted.empty())//выходим из цикла если отсортированный стек пуст
						break;
				}
				sorted.push(ini_top);
			}
		}		
	}	
	cout<<"Отсортированный стек:"<<endl;
	while(!sorted.empty())
	{
		cout<<sorted.top()<<"; ";
		sorted.pop();	
	}	
	cout<<endl;
	return 0;
}