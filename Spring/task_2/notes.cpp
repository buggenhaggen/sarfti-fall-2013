#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
// структура, описывающая один узел:
struct Node
{
	int data; // элемент данных
	Node *next, *prev; // указатели на следующий и предыдущий узел
};
// класс для работы с очередью:
class QueueInt
{
	/* указатели на начало, конец списка  и на текущий узел (указатель на текущий узел используется многими функциями, поэтому объявим его как элемент данных класса): */
	Node *front_node;
	Node *back_node;
	// функция вывода:
	friend ostream& operator << (ostream&,QueueInt&);
private:
	Node *token;
public:
	QueueInt() {back_node = front_node = token = NULL;} 
	QueueInt(const QueueInt&); // конструктор копирования
	~QueueInt(); // деструктор
	bool empty() { return front_node == NULL ? true: false;} // проверка, пустая ли очередь
	int front() {return front_node->data;}
	int back() {return front_node->data;}
	void push(int val); //добавляет элемент в конец списка
	void pop500();//удаляем первые 500 эл-ов из очереди
	int size(); // количество элементов очереди
private:
	int Gettoken(); // текущий элемент данных
};
// Определение функций:
// конструктор копирования:
QueueInt ::QueueInt(const QueueInt& list)
{
	back_node = front_node = token = NULL;
	Node* ptr = list.front_node;
	// указатель на текущий элемент копируемого объекта
	while  (ptr)
	{
		push(ptr->data); 
		// добавляем в очередь элемент из копируемого очереди
		ptr = ptr->next; 
		// переходим к следующему элементу копируемого очереди
	}
}

//  функция, которая добавляет элемент в конец списка:
void QueueInt :: push(int val)
{
	Node *p = new Node; // создаем новый узел
	p->data = val; // записываем элемент данных
	if(empty()) // если очередь еще пуст
	{
		front_node = back_node = p; 
		// добавляемый элемент становится первым и последним
		p->next = p->prev = NULL; 
		//  предыдущего и последующего элементов нет
	}
	else
	{
		back_node->next = p;  // привязываем новый узел к последнему
		p->prev=back_node; p->next = NULL; // определяем значения указателей
		back_node=p; // новый узел становится последним
	}
}

void QueueInt::pop500()
{
	int i = 0;
	if (!this->empty())
	{
		if (size() < 500)
		{
			front_node = back_node = NULL;
		}
		else
		{			
			while(i < 500)
			{
				Gettoken();
				i++;
			}
			token->prev =NULL;
			front_node = token;
		}
	}
}

//функция, которая определяет значение текущего элемента
int QueueInt :: Gettoken()
{
	if (token == NULL) token = front_node;
	if (token)
	{
		int rv = token->data; //считываем значение из текущего узла
		token = token->next; //текущим становится следующий узел
		return rv;
	}
	else return 0;
}

// функция вывода:
ostream& operator << (ostream& os,QueueInt& q)
{
	int i = 1;
	q.token = q.front_node; // переходим в начало списка q
	while(q.token) // пока очередь не закончена
	{
		cout<<i<<":\t";
		os << q.Gettoken(); // выводим очередной элемент списка
		cout<<endl;
		i++;
	}
	return os << endl;
}

//деструктор:
QueueInt :: ~QueueInt()
//Удаляет элементы cписка с конца:
{
	while (back_node) // если очередь не пустой
	{
		token = back_node; // берем последний узел
		back_node = back_node->prev; // предпоследний узел делаем последним
		delete token; // удаляем узел
		if (token==front_node) break; 
		// если удалили первый узел, то останавливаем цикл
	}
}
// функция возвращает количество элементов списка
int QueueInt::size()
{
	int count=0;
	token = front_node;
	while (token)
	{
		count++; // увеличиваем счетчик
		token = token->next; // переходим к следующему узлу
	}
	return count;
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
	QueueInt queue_a;
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	do
	{
		for (int  i = 0; i < 510; i++ )
		{
			//заполним исходный стек случайными значениями из диапозона [-1000; 1000] 
			queue_a.push((double)rand() / (RAND_MAX + 1) * (1000 - (-1000))	+ (-1000));		
		}
		cout<<"Исходная очередь:\n"<<queue_a;
		queue_a.pop500();//забираем первые 500 эл-ов
		cout<<"Оставшиеся элементы: \n"<<queue_a;
	} while (_getch() != 27);
	return 0;
}

