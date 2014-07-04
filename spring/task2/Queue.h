#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
// структура, описывающая один узел:
struct Node
{
	int data; // элемент данных
	Node *next, *previous; // указатели на следующий и предыдущий узел
};
// класс для работы с очередью:
class Queue
{
	/* указатели на начало, конец списка  и на текущий узел (указатель на текущий узел используется многими функциями, поэтому объявим его как элемент данных класса): */
	Node *front;
	Node *back;
	// функция вывода:
	friend ostream& operator << (ostream&,Queue&);
private:
	Node *token;
public:
	Queue() {back = front = token = NULL;} 
	~Queue(); // деструктор
	bool empty() { return front == NULL ? true: false;} // проверка, пустая ли очередь
	void push(int val); //добавляет элемент в конец списка
	void pop_first_500();//удаляем первые 500 эл-ов из очереди
	int count(); // количество элементов очереди
private:
	int current(); // текущий элемент данных
};
// Определение функций:
//  функция, которая добавляет элемент в конец списка:
void Queue :: push(int val)
{
	Node *p = new Node; // создаем новый узел
	p->data = val; // записываем элемент данных
	if(empty()) // если очередь еще пуст
	{
		front = back = p; 
		// добавляемый элемент становится первым и последним
		p->next = p->previous = NULL; 
		//  предыдущего и последующего элементов нет
	}
	else
	{
		back->next = p;  // привязываем новый узел к последнему
		p->previous=back; p->next = NULL; // определяем значения указателей
		back=p; // новый узел становится последним
	}
}
void Queue::pop_first_500()
{
	int i = 0;
	if (!this->empty())
	{
		if (count() <= 500)
		{
			front = back = NULL;
		}
		else
		{			
			while(i < 500)
			{
				current();
				i++;
			}
			token->previous =NULL;
			front = token;
		}
	}
}
//функция, которая определяет значение текущего элемента
int Queue :: current()
{
	if (token == NULL) token = front;
	if (token)
	{
		int rv = token->data; //считываем значение из текущего узла
		token = token->next; //текущим становится следующий узел
		return rv;
	}
	else return 0;
}
// функция вывода:
ostream& operator << (ostream& os,Queue& q)
{
	q.token = q.front; // переходим в начало списка q
	while(q.token) // пока очередь не закончена
	{		
		os << q.current(); // выводим очередной элемент списка
		cout<<" ";		
	}
	return os << endl;
}

//деструктор:
Queue :: ~Queue()
//Удаляет элементы cписка с конца:
{
	while (back) // если очередь не пустой
	{
		token = back; // берем последний узел
		back = back->previous; // предпоследний узел делаем последним
		delete token; // удаляем узел
		if (token==front) break; 
		// если удалили первый узел, то останавливаем цикл
	}
}
// функция возвращает количество элементов списка
int Queue::count()
{
	int count=0;
	token = front;
	while (token)
	{
		count++; // увеличиваем счетчик
		token = token->next; // переходим к следующему узлу
	}
	return count;
}