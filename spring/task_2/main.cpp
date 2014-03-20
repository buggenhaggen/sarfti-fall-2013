#include "queue.h"
#include <iostream>
#include <conio.h>
using namespace std;
 
int main()
{
	setlocale(LC_ALL,"Russian");
    queue q;
    q.init();
	cout<<"Положить элемент: \n";
	for(int n=0; n<=502; n++)//вызов функции происходит 502 разa, чтобы заполнить очередь. Очередь заполняется по 1 элементу
	{
    q.put(n);
	}
	cout<<"\n";
    q.get();//из очереди считывается сразу 500 элементов
	getch();
}