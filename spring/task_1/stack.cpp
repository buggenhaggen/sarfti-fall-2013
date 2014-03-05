//реализация алгоритма сортировки стека по возростанию

#include "conio.h"
#include "iostream"
#include "stack"
 
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
 
    stack<int> original;//первый стек 
    stack<int> auxiliary;//второй вспомогательный стек
    
    int i;//первая переменная
    cout <<"Первый стек: \n";
    for(int i = 5; i >= 0; --i) //заполняем первый стек случайными значениями
    {
        original.push(rand()%21);
        cout << original.top() << " ";//выводим значение самого верхнего элемента
    }
 
    cout <<"\n";
    int m;//вторая переменная
    for(i=0;i<5;i++)
{
	m=original.top();//присваиваем m значение верхнего элемента
	original.pop();//удаляем его из стека
	while(!original.empty())//пока первый стек не закончен
	{
		if(m<original.top())
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
    cout << "Результат сортировки стека: \n";//вывод результата
    while(!original.empty()) {
        cout << original.top() << " ";
        original.pop();
    }
        
    getch();
}