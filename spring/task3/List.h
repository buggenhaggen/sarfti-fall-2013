#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next; // ��������� �� ��������� 
};

// ����� ��� ������ �� �������:
class MyList
{
	/* ��������� �� ������, ����� ������  � �� ������� ���� (��������� �� ������� ���� ������������ ������� ���������, ������� ������� ��� ��� ������� ������ ������): */
	Node *front;
	Node *back;
	Node *token;
	// ������� �����-������:
	friend ostream& operator << (ostream&, MyList&);
	friend istream& operator >> (istream&, MyList&);
public:
	MyList() {back = front = token = NULL;} 
	// ����������� �� ���������
	MyList(int, int*); // �������� �����������
	MyList(const MyList&); // ����������� �����������
	~MyList(); // ����������
	bool Empty() { return front == NULL ? true: false;} 
	// ��������, ������ �� ������ 
	void Add(int val); //��������� ������� � ����� ������
	void AddToListCenter(int val);
	int GetToken(); // ������� ������� ������
	int GetCount(); // ���������� ��������� ������
};
// ����������� �������:
// �������� �����������
MyList :: MyList (int n, int* val) 
// ����������� �������� ���������� ��������� ������� � ��������� �� ������
{
	back = front = token  = NULL;
	for (int i=0; i<n; i++)
		Add(val[i]); // ��������� �������� ������� � ������
}
// ����������� �����������:
MyList :: MyList(const MyList& list)
{
	back = front = token = NULL;
	Node* ptr = list.front;
	// ��������� �� ������� ������� ����������� �������
	while  (ptr)
	{
		Add(ptr->data); 
		// ��������� � ������ ������� �� ����������� ������
		ptr = ptr->next; 
		// ��������� � ���������� �������� ����������� ������
	}
}

//  �������, ������� ��������� ������� � ����� ������:
void MyList :: Add(int val)
{
	Node *p = new Node; // ������� ����� ����
	p->data = val; // ���������� ������� ������
	if(Empty()) // ���� ������ ��� ����
	{
		front = back = p; 
		// ����������� ������� ���������� ������ � ���������
		p->next = NULL; 
		//  ����������� � ������������ ��������� ���
	}
	else
	{
		back->next = p;  // ����������� ����� ���� � ����������
		p->next = NULL; // ���������� �������� ����������
		back=p; // ����� ���� ���������� ���������
	}
}
//  �������, ������� ��������� ������� � �������� ������ ������:
void MyList :: AddToListCenter(int val)
{
	Node *p = new Node; // ������� ����� ����
	Node *prev_node = front;
	p->data = val; // ���������� ������� ������
	if(Empty()) // ���� ������ ��� ����
	{
		front = back = p; 
		// ����������� ������� ���������� ������ � ���������
		p->next = NULL; 
		//  ����������� � ������������ ��������� ���
	}
	else
	{
		int pos = GetCount()/2; //���������� ������� ������������ ��-��
		for (int i = 1 ; i < pos; i++)
		{
			prev_node = prev_node->next; 
		}
		p->next = prev_node->next;
		prev_node->next = p;  // ����������� ����� ���� � ������������

	}
}
//������� �����:
istream & operator >> (istream &is, MyList& q)
{
	q.~MyList(); // ������� ����� �������������� ������
	int a; int k;
	cout<<"������� ��������� ������ �������? ";
	is >> k;
	for(int i=0; i<k; i++)
	{
		cout << i+1 << ": "; is >> a;
		q.Add(a);
	}
	return is;
}

//�������, ������� ���������� �������� �������� ��������
int MyList :: GetToken()
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
ostream& operator << (ostream& os, MyList& q)
{
	q.token = q.front; // ��������� � ������ ������ q
	while(q.token) // ���� ������ �� ��������
	{
		if (q.token != q.front)
			cout <<" ";
		os << q.GetToken(); // ������� ��������� ������� ������
	}
	return os << endl;
}

//����������:
MyList :: ~MyList()
//������� �������� c����� � �����:
{
	while (back) // ���� ������ �� ������
	{
		token = back; // ����� ��������� ����
		delete token; // ������� ����
		if (token==front) break; 
		// ���� ������� ������ ����, �� ������������� ����
	}
}
// ������� ���������� ���������� ��������� ������
int MyList::GetCount()
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



