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
class MyQueue
{
	/* ��������� �� ������, ����� ������  � �� ������� ���� (��������� �� ������� ���� ������������ ������� ���������, ������� ������� ��� ��� ������� ������ ������): */
	Node *front_node;
	Node *back_node;
	// ������� ������:
	friend ostream& operator << (ostream&,MyQueue&);
private:
	Node *token;
public:
	MyQueue() {back_node = front_node = token = NULL;} 
	MyQueue(const MyQueue&); // ����������� �����������
	~MyQueue(); // ����������
	bool empty() { return front_node == NULL ? true: false;} // ��������, ������ �� �������
	int front() {return front_node->data;}
	int back() {return front_node->data;}
	void push(int val); //��������� ������� � ����� ������
	void pop();//������� ������ 500 ��-�� �� �������
	int size(); // ���������� ��������� �������
private:
	int cur_token(); // ������� ������� ������
};
// ����������� �������:
// ����������� �����������:
MyQueue ::MyQueue(const MyQueue& list)
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
void MyQueue :: push(int val)
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

void MyQueue::pop()
{
	int i = 0;
	if (!this->empty())
	{
		if (size() <= 500)
		{
			front_node = back_node = NULL;
		}
		else
		{			
			while(i < 500)
			{
				cur_token();
				i++;
			}
			token->prev =NULL;
			front_node = token;
		}
	}
}

//�������, ������� ���������� �������� �������� ��������
int MyQueue :: cur_token()
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
ostream& operator << (ostream& os,MyQueue& q)
{
	q.token = q.front_node; // ��������� � ������ ������ q
	while(q.token) // ���� ������� �� ���������
	{		
		os << q.cur_token(); // ������� ��������� ������� ������
		cout<<";\t";		
	}
	return os << endl;
}

//����������:
MyQueue :: ~MyQueue()
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
int MyQueue::size()
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
	MyQueue que;
	
	int count;
	
	//�������������� ������
	srand((unsigned)time( NULL )); 
	do
	{
		cout<<"������� ���������� ��-�� �������: ";
		cin>>count;
		for (int  i = 0; i < count; i++ )
		{
			//�������� �������� ���� ���������� ���������� �� ��������� [0; 100] 
			que.push((double)rand() / (RAND_MAX + 1) * 1000);		
		}
		cout<<"�������� �������:\n"<<que;
		que.pop();//�������� ������ 500 ��-��
		cout<<"���������� ��������: \n"<<que;
	} while (_getch() != 27);
	return 0;
}

