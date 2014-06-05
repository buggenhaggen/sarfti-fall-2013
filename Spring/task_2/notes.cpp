#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next, *prev; // ��������� �� ��������� � ���������� ����
};
// ����� ��� ������ � ��������:
class QueueInt
{
	/* ��������� �� ������, ����� ������  � �� ������� ���� (��������� �� ������� ���� ������������ ������� ���������, ������� ������� ��� ��� ������� ������ ������): */
	Node *front_node;
	Node *back_node;
	// ������� ������:
	friend ostream& operator << (ostream&,QueueInt&);
private:
	Node *token;
public:
	QueueInt() {back_node = front_node = token = NULL;} 
	QueueInt(const QueueInt&); // ����������� �����������
	~QueueInt(); // ����������
	bool empty() { return front_node == NULL ? true: false;} // ��������, ������ �� �������
	int front() {return front_node->data;}
	int back() {return front_node->data;}
	void push(int val); //��������� ������� � ����� ������
	void pop500();//������� ������ 500 ��-�� �� �������
	int size(); // ���������� ��������� �������
private:
	int Gettoken(); // ������� ������� ������
};
// ����������� �������:
// ����������� �����������:
QueueInt ::QueueInt(const QueueInt& list)
{
	back_node = front_node = token = NULL;
	Node* ptr = list.front_node;
	// ��������� �� ������� ������� ����������� �������
	while  (ptr)
	{
		push(ptr->data); 
		// ��������� � ������� ������� �� ����������� �������
		ptr = ptr->next; 
		// ��������� � ���������� �������� ����������� �������
	}
}

//  �������, ������� ��������� ������� � ����� ������:
void QueueInt :: push(int val)
{
	Node *p = new Node; // ������� ����� ����
	p->data = val; // ���������� ������� ������
	if(empty()) // ���� ������� ��� ����
	{
		front_node = back_node = p; 
		// ����������� ������� ���������� ������ � ���������
		p->next = p->prev = NULL; 
		//  ����������� � ������������ ��������� ���
	}
	else
	{
		back_node->next = p;  // ����������� ����� ���� � ����������
		p->prev=back_node; p->next = NULL; // ���������� �������� ����������
		back_node=p; // ����� ���� ���������� ���������
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

//�������, ������� ���������� �������� �������� ��������
int QueueInt :: Gettoken()
{
	if (token == NULL) token = front_node;
	if (token)
	{
		int rv = token->data; //��������� �������� �� �������� ����
		token = token->next; //������� ���������� ��������� ����
		return rv;
	}
	else return 0;
}

// ������� ������:
ostream& operator << (ostream& os,QueueInt& q)
{
	int i = 1;
	q.token = q.front_node; // ��������� � ������ ������ q
	while(q.token) // ���� ������� �� ���������
	{
		cout<<i<<":\t";
		os << q.Gettoken(); // ������� ��������� ������� ������
		cout<<endl;
		i++;
	}
	return os << endl;
}

//����������:
QueueInt :: ~QueueInt()
//������� �������� c����� � �����:
{
	while (back_node) // ���� ������� �� ������
	{
		token = back_node; // ����� ��������� ����
		back_node = back_node->prev; // ������������� ���� ������ ���������
		delete token; // ������� ����
		if (token==front_node) break; 
		// ���� ������� ������ ����, �� ������������� ����
	}
}
// ������� ���������� ���������� ��������� ������
int QueueInt::size()
{
	int count=0;
	token = front_node;
	while (token)
	{
		count++; // ����������� �������
		token = token->next; // ��������� � ���������� ����
	}
	return count;
}
//=========================================================
int main()
{
	////��������� ������� � ������������ ����������: 
	//if(SetConsoleCP(1251)==0)
	//	//�������� ������������ ��������� ��������� �������� ��� �����
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//	/* ���� �� ������� ���������� ������� ��������, ����� ��������� �� ������ */
	//}
	//if(SetConsoleOutputCP(1251)==0)//���� ����� ��� ������
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}
	setlocale(LC_ALL, "Russian");
	QueueInt queue_a;
	//�������������� ������
	srand((unsigned)time( NULL )); 
	do
	{
		for (int  i = 0; i < 510; i++ )
		{
			//�������� �������� ���� ���������� ���������� �� ��������� [-1000; 1000] 
			queue_a.push((double)rand() / (RAND_MAX + 1) * (1000 - (-1000))	+ (-1000));		
		}
		cout<<"�������� �������:\n"<<queue_a;
		queue_a.pop500();//�������� ������ 500 ��-��
		cout<<"���������� ��������: \n"<<queue_a;
	} while (_getch() != 27);
	return 0;
}

