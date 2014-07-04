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
class ListIterator
{
public:
	Node *pt;
	ListIterator():pt(0){}
	ListIterator(Node *pn):pt(pn){}
	int operator*(){return pt->data;}
	ListIterator operator++(int)
	{
		ListIterator tmp = *this;
		pt = pt->next;
		return tmp;
	}
	ListIterator operator--(int)
	{
		ListIterator tmp = *this;
		pt = pt->previous;
		return tmp;
	}
};
// класс для работы со списком:
class MyList
{
	/* указатели на начало, конец списка  и на текущий узел (указатель на текущий узел используется многими функциями, поэтому объявим его как элемент данных класса): */
	Node *front;
	Node *back;
	Node *token;
	// функции ввода-вывода:
	friend ostream& operator << (ostream&, MyList&);
	friend istream& operator >> (istream&, MyList&);
public:
	MyList() {back = front = token = NULL;} 
	// конструктор по умолчанию
	MyList(int, int*); // основной конструктор
	MyList(const MyList&); // конструктор копирования
	~MyList(); // деструктор
	bool Empty() { return front == NULL ? true: false;} 
	// проверка, пустой ли список 
	void Add(int val); //добавляет элемент в конец списка
	int GetToken(); // текущий элемент данных
	int GetCount(); // количество элементов списка
	ListIterator Begin(){ ListIterator iter(front); return iter; }
	ListIterator LastItem(){	ListIterator iter(back); return iter; }
};
// Определение функций:
// Основной конструктор
MyList :: MyList (int n, int* val) 
// параметрами являются количество элементов массива и указатель на массив
{
	back = front = token  = NULL;
	for (int i=0; i<n; i++)
		Add(val[i]); // добавляем элементы массива в список
}
// конструктор копирования:
MyList :: MyList(const MyList& list)
{
	back = front = token = NULL;
	Node* ptr = list.front;
	// указатель на текущий элемент копируемого объекта
	while  (ptr)
	{
		Add(ptr->data); 
		// добавляем в список элемент из копируемого списка
		ptr = ptr->next; 
		// переходим к следующему элементу копируемого списка
	}
}

//  функция, которая добавляет элемент в конец списка:
void MyList :: Add(int val)
{
	Node *p = new Node; // создаем новый узел
	p->data = val; // записываем элемент данных
	if(Empty()) // если список еще пуст
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
//функция ввода:
istream & operator >> (istream &is, MyList& q)
{
	q.~MyList(); // Удаляем ранее существовавший список
	int a; int k;
	cout<<"Сколько элементов будете вводить? ";
	is >> k;
	for(int i=0; i<k; i++)
	{
		cout << i+1 << ": "; is >> a;
		q.Add(a);
	}
	return is;
}
//функция, которая определяет значение текущего элемента
int MyList :: GetToken()
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
ostream& operator << (ostream& os, MyList& q)
{
	os << "< ";
	q.token = q.front; // переходим в начало списка q
	while(q.token) // пока список не закончен
	{
		if (q.token != q.front)
			cout <<", ";
		os << q.GetToken(); // выводим очередной элемент списка
	}
	return os << ">" << endl;
}
//деструктор:
MyList :: ~MyList()
//Удаляет элементы cписка с конца:
{
	while (back) // если список не пустой
	{
		token = back; // берем последний узел
		back = back->previous; // предпоследний узел делаем последним
		delete token; // удаляем узел
		if (token==front) break; 
		// если удалили первый узел, то останавливаем цикл
	}
}
// функция возвращает количество элементов списка
int MyList::GetCount()
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

