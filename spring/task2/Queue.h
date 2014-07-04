#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next, *previous; // ��������� �� ��������� � ���������� ����
};
// ����� ��� ������ � ��������:
class Queue
{
	/* ��������� �� ������, ����� ������  � �� ������� ���� (��������� �� ������� ���� ������������ ������� ���������, ������� ������� ��� ��� ������� ������ ������): */
	Node *front;
	Node *back;
	// ������� ������:
	friend ostream& operator << (ostream&,Queue&);
private:
	Node *token;
public:
	Queue() {back = front = token = NULL;} 
	~Queue(); // ����������
	bool empty() { return front == NULL ? true: false;} // ��������, ������ �� �������
	void push(int val); //��������� ������� � ����� ������
	void pop_first_500();//������� ������ 500 ��-�� �� �������
	int count(); // ���������� ��������� �������
private:
	int current(); // ������� ������� ������
};
// ����������� �������:
//  �������, ������� ��������� ������� � ����� ������:
void Queue :: push(int val)
{
	Node *p = new Node; // ������� ����� ����
	p->data = val; // ���������� ������� ������
	if(empty()) // ���� ������� ��� ����
	{
		front = back = p; 
		// ����������� ������� ���������� ������ � ���������
		p->next = p->previous = NULL; 
		//  ����������� � ������������ ��������� ���
	}
	else
	{
		back->next = p;  // ����������� ����� ���� � ����������
		p->previous=back; p->next = NULL; // ���������� �������� ����������
		back=p; // ����� ���� ���������� ���������
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
//�������, ������� ���������� �������� �������� ��������
int Queue :: current()
{
	if (token == NULL) token = front;
	if (token)
	{
		int rv = token->data; //��������� �������� �� �������� ����
		token = token->next; //������� ���������� ��������� ����
		return rv;
	}
	else return 0;
}
// ������� ������:
ostream& operator << (ostream& os,Queue& q)
{
	q.token = q.front; // ��������� � ������ ������ q
	while(q.token) // ���� ������� �� ���������
	{		
		os << q.current(); // ������� ��������� ������� ������
		cout<<" ";		
	}
	return os << endl;
}

//����������:
Queue :: ~Queue()
//������� �������� c����� � �����:
{
	while (back) // ���� ������� �� ������
	{
		token = back; // ����� ��������� ����
		back = back->previous; // ������������� ���� ������ ���������
		delete token; // ������� ����
		if (token==front) break; 
		// ���� ������� ������ ����, �� ������������� ����
	}
}
// ������� ���������� ���������� ��������� ������
int Queue::count()
{
	int count=0;
	token = front;
	while (token)
	{
		count++; // ����������� �������
		token = token->next; // ��������� � ���������� ����
	}
	return count;
}