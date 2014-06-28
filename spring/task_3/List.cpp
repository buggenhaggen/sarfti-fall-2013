#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next; // ��������� �� ��������� 
};

// ����� ��� ������ �� �������:
class ListInt
{
	/* ��������� �� ������, ����� ������  � �� ������� ���� (��������� �� ������� ���� ������������ ������� ���������, ������� ������� ��� ��� ������� ������ ������): */
	Node *front;
	Node *back;
	Node *token;
	// ������� �����-������:
	friend ostream& operator << (ostream&, ListInt&);
	friend istream& operator >> (istream&, ListInt&);
public:
	ListInt() {back = front = token = NULL;} 
	// ����������� �� ���������
	ListInt(int, int*); // �������� �����������
	ListInt(const ListInt&); // ����������� �����������
	~ListInt(); // ����������
	bool Empty() { return front == NULL ? true: false;} 
	// ��������, ������ �� ������ 
	void Add(int val); //��������� ������� � ����� ������
	void AddMidle(int val);
	int Gettoken(); // ������� ������� ������
	int GetSize(); // ���������� ��������� ������
	ListInt& operator () (int n, int v); 
	// ��������, ������� �������� ������� � ������� n �� �������� �������� v
	// ����� ���� �������� () �������� ��������������� ��� �������� +
	ListInt& operator + ();
	// ��������, ������� ��������� ������� � ������ � ������� �������
};
// ����������� �������:
// �������� �����������
ListInt :: ListInt (int n, int* val) 
// ����������� �������� ���������� ��������� ������� � ��������� �� ������
{
	back = front = token  = NULL;
	for (int i=0; i<n; i++)
		Add(val[i]); // ��������� �������� ������� � ������
}
// ����������� �����������:
ListInt :: ListInt(const ListInt& list)
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
void ListInt :: Add(int val)
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
void ListInt :: AddMidle(int val)
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
		int pos = GetSize()/2; //���������� ������� ������������ ��-��
		for (int i = 1 ; i < pos; i++)
		{
			prev_node = prev_node->next; 
		}
		p->next = prev_node->next;
		prev_node->next = p;  // ����������� ����� ���� � ������������
		
	}
}
//������� �����:
istream & operator >> (istream &is, ListInt& q)
{
	q.~ListInt(); // ������� ����� �������������� ������
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
int ListInt :: Gettoken()
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
ostream& operator << (ostream& os, ListInt& q)
{
	os << "< ";
	q.token = q.front; // ��������� � ������ ������ q
	while(q.token) // ���� ������ �� ��������
	{
		if (q.token != q.front)
			cout <<", ";
		os << q.Gettoken(); // ������� ��������� ������� ������
	}
	return os << ">" << endl;
}

//����������:
ListInt :: ~ListInt()
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
int ListInt::GetSize()
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

// �������� ():
ListInt& ListInt:: operator () (int n, int v)
// ����������� ������� �������� ����� �������� � ����� �������� ����� 
// ��������
{		
	Node *ptr;
	if (n <= GetSize())
	{
		// ������� ����� �������� � �������� �������:
		ptr = front;
		for (int i=1; i<n; i++)
			ptr = ptr->next;
		Node* tmp = new Node; 
		// ������� ����� ���� (�� ����� ������� ����� ����������� ����)
		tmp->data = ptr->data; // �������� ���������� ����		
		tmp->next = ptr->next; 		
		ptr->data = v; // �������� �������� �������� �������� �� v
	}
	else // ���� ��������� ����� ���� � ����� ������
	{
		Node* tmp = new Node; // ������� ����� ����
		tmp->data = v;
		tmp->next = NULL;
		// �������� ����������� ��� ����� ������ ����� ������
		ptr = back;
		back = tmp;
	}
	token = ptr;
	return *this; // ���������� ������� ������
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
	int a[]={1, -2, 3, -4, 5};
	ListInt lista(5, a);
	cout<<"����������� ������: \n";
	cout << lista;

	// ������ ������������� �������� () � + :
	do
	{
		cout<<"������� �����: ";
		int val;
		cin>>val;
		lista.AddMidle(val);
		cout << lista;
	} while (_getch() != 27);
	return 0;
}
