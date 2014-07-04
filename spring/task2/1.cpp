#include "Queue.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////
int main()
{
	//установка поддержки русских шрифтов
	setlocale(LC_ALL, "Russian");
	Queue queue;
	int count;
	//инициализируем рандомайз 
	srand((unsigned)time( NULL )); 
	do
	{
		cout<<"Введите количество элементов очереди ";
		cin>>count;
		int i = 0;
		while(i < count)
		{
			//заполним исходный стек случайными значениями от 0 до 100
			queue.push(rand()%100);	
			i++;
		}
		cout<<"Исходная очередь:\n"<<queue;
		queue.pop_first_500();//убираем 500 эл-ов с начала очереди
		cout<<"Оставшиеся элементы: \n"<<queue;
	} while (_getch() != 27);
	return 0;
}

