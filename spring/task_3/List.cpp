#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

// структура, описывающая один узел:
struct Node
{
	int data; // элемент данных
	Node *next; // указатели на следующий 
};

// класс для работы со списком:
class ListInt
{
	/* указатели на начало, конец списка  и на текущий узел (указатель на текущий узел используется многими функциями, поэтому объявим его как элемент данных класса): */
	Node *front;
	Node *back;
	Node *token;
	// функции ввода-вывода:
	friend ostream& operator << (ostream&, ListInt&);
	friend istream& operator >> (istream&, ListInt&);
public:
	ListInt() {back = front = token = NULL;} 
	// конструктор по умолчанию
	ListInt(int, int*); // основной конструктор
	ListInt(const ListInt&); // конструктор копирования
	~ListInt(); // деструктор
	bool Empty() { return front == NULL ? true: false;} 
	// проверка, пустой ли список 
	void Add(int val); //добавляет элемент в конец списка
	void AddMidle(int val);
	int Gettoken(); // текущий элемент данных
	int GetSize(); // количество элементов списка
	ListInt& operator () (int n, int v); 
	// операция, которая заменяет элемент с номером n на заданное значение v
	// кроме того операция () является вспомогательной для операции +
	ListInt& operator + ();
	// операция, которая добавляет элемент в список в текущей позиции
};
// Определение функций:
// Основной конструктор
ListInt :: ListInt (int n, int* val) 
// параметрами являются количество элементов массива и указатель на массив
{
	back = front = token  = NULL;
	for (int i=0; i<n; i++)
		Add(val[i]); // добавляем элементы массива в список
}
// конструктор копирования:
ListInt :: ListInt(const ListInt& list)
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
void ListInt :: Add(int val)
{
	Node *p = new Node; // создаем новый узел
	p->data = val; // записываем элемент данных
	if(Empty()) // если список еще пуст
	{
		front = back = p; 
		// добавляемый элемент становится первым и последним
		p->next = NULL; 
		//  предыдущего и последующего элементов нет
	}
	else
	{
		back->next = p;  // привязываем новый узел к последнему
		p->next = NULL; // определяем значения указателей
		back=p; // новый узел становится последним
	}
}
//  функция, которая добавляет элемент в середину списка списка:
void ListInt :: AddMidle(int val)
{
	Node *p = new Node; // создаем новый узел
	Node *prev_node = front;
	p->data = val; // записываем элемент данных
	if(Empty()) // если список еще пуст
	{
		front = back = p; 
		// добавляемый элемент становится первым и последним
		p->next = NULL; 
		//  предыдущего и последующего элементов нет
	}
	else
	{
		int pos = GetSize()/2; //определяем позицию вставляемого эл-та
		for (int i = 1 ; i < pos; i++)
		{
			prev_node = prev_node->next; 
		}
		p->next = prev_node->next;
		prev_node->next = p;  // привязываем новый узел к предъидущему
		
	}
}
//функция ввода:
istream & operator >> (istream &is, ListInt& q)
{
	q.~ListInt(); // Удаляем ранее существовавший список
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
int ListInt :: Gettoken()
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
ostream& operator << (ostream& os, ListInt& q)
{
	os << "< ";
	q.token = q.front; // переходим в начало списка q
	while(q.token) // пока список не закончен
	{
		if (q.token != q.front)
			cout <<", ";
		os << q.Gettoken(); // выводим очередной элемент списка
	}
	return os << ">" << endl;
}

//деструктор:
ListInt :: ~ListInt()
//Удаляет элементы cписка с конца:
{
	while (back) // если список не пустой
	{
		token = back; // берем последний узел
		delete token; // удаляем узел
		if (token==front) break; 
		// если удалили первый узел, то останавливаем цикл
	}
}

// функция возвращает количество элементов списка
int ListInt::GetSize()
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

// операция ():
ListInt& ListInt:: operator () (int n, int v)
// параметрами функции являются номер элемента и новое значение этого 
// элемента
{		
	Node *ptr;
	if (n <= GetSize())
	{
		// находим адрес элемента с заданным номером:
		ptr = front;
		for (int i=1; i<n; i++)
			ptr = ptr->next;
		Node* tmp = new Node; 
		// создаем новый узел (он будет хранить копию заменяемого узла)
		tmp->data = ptr->data; // копируем содержимое узла		
		tmp->next = ptr->next; 		
		ptr->data = v; // заменяем значение текущего элемента на v
	}
	else // Если вставляем новый узел в конец списка
	{
		Node* tmp = new Node; // Создаем новый узел
		tmp->data = v;
		tmp->next = NULL;
		// временно подвязываем его перед первым узлом списка
		ptr = back;
		back = tmp;
	}
	token = ptr;
	return *this; // возвращаем текущий объект
}


//=========================================================
int main()
{
	////Настройки шрифтов и региональных стандартов: 
	//if(SetConsoleCP(1251)==0)
	//	//проверка правильности установки кодировки символов для ввода
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//	/* если не удалось установить кодовую страницу, вывод сообщения об ошибке */
	//}
	//if(SetConsoleOutputCP(1251)==0)//тоже самое для вывода
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}
	setlocale(LC_ALL, "Russian");
	int a[]={1, -2, 3, -4, 5};
	ListInt lista(5, a);
	cout<<"Изначальный список: \n";
	cout << lista;

	// пример использования операций () и + :
	do
	{
		cout<<"Введите число: ";
		int val;
		cin>>val;
		lista.AddMidle(val);
		cout << lista;
	} while (_getch() != 27);
	return 0;
}
