#include <iostream>
using namespace std;

struct Queue
{
	int* first;
	int* last;
};


void insert_queue(Queue &q, int val)
{
	q.last = q.last+1;
	*(q.last) = val;
}



void get_500(Queue &q, int *m)
{
	for(int i = 0; i<500; i++)
	{
		m[i] = *q.first;
		q.first ++;
	}
}



void main()
{
	Queue q;
	int main_mas[100000];

	int get_mas[500];

	q.first  = main_mas;
	q.last = main_mas - 1;

	cout<<"QUEUE:\n\n";



	//Вставка в очередь
	for(int i = 0; i<2000; i++)
	{
		insert_queue(q,i+20);
	}

	//Получение первых 500 элементов
	get_500(q,get_mas);

	cout<<"first 20 elements from queue:\n";
	//Вывод первых 20 полученных элементов
	for(int i = 0; i< 20; i++)
		cout<<get_mas[i]<<" ";
	cout<<endl;

}