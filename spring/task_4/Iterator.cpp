#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

// ���������, ����������� ���� ����:
struct Node
{
	int data; // ������� ������
	Node *next, *prev; // ��������� �� ��������� � ���������� ����
};
class iter
{
public:
	Node *pt;
	iter():pt(0){}
	iter(Node *pn):pt(pn){}
	int operator*(){return pt->data;}
	iter operator++(int)
	{
		iter tmp = *this;
		pt = pt->next;
		return tmp;
	}
	iter operator--(int)
	{
		iter tmp = *this;
		pt = pt->prev;
		return tmp;
	}

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
	int Gettoken(); // ������� ������� ������
	int GetSize(); // ���������� ��������� ������
	ListInt& operator () (int n, int v); 
	iter Begin(){
		iter pt(front);
		return pt;
	}
	iter End(){
		iter pt(back);
		return pt;
	}
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
		p->next = p->prev = NULL; 
		//  ����������� � ������������ ��������� ���
	}
	else
	{
		back->next = p;  // ����������� ����� ���� � ����������
		p->prev=back; p->next = NULL; // ���������� �������� ����������
		back=p; // ����� ���� ���������� ���������
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
		back = back->prev; // ������������� ���� ������ ���������
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
		tmp->prev = ptr->prev; 
		tmp->next = ptr->next; 
		front->prev = tmp; // �������� ����������� ����� ����� ������ ����� ������
		ptr->data = v; // �������� �������� �������� �������� �� v
	}
	else // ���� ��������� ����� ���� � ����� ������
	{
		Node* tmp = new Node; // ������� ����� ����
		tmp->data = v;
		tmp->prev = back;
		tmp->next = NULL;
		front->prev = tmp; 
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
	cout<<"�������� ������ � ������ � �������� �������: \n";
	//cout << lista;
	iter p = lista.Begin();
	iter r = lista.End();
	for (int i = 0; i < lista.GetSize(); i++, p++, r--)
	{
		cout<<*p<<"\t"<<*r<<"\n";
	}

	// ������ ������������� �������� () � + :
	do
	{
		
	} while (_getch() != 27);
	return 0;
}

