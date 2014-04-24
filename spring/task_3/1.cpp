#include <iostream>
#include <fstream>
 
using namespace std;
 
struct Node
{   int x;
    Node *Next;
};
 
class List
{   Node *Head, *Tail;
    int size;
public:
    List() :Head(NULL), Tail(NULL), size(0){};
    void PushBack (int x)
    {   Node *pnew = new Node;
        pnew->x = x;
        
        if (!size)
        {   Head = Tail = pnew;
            Head->Next = Tail->Next = NULL;
            size++;
            return;
        }
 
        Tail->Next = pnew;
        Tail = pnew;
        Tail->Next = NULL;
        size++;
    }
 
    void Insert (int x, int pos)
    {                  
        Node *pnew = new Node;
        pnew->x = x;
 
        if (pos == 1)
        {   pnew->Next = Head;
            Head = pnew;
            size++;
            return;
        }
 
        Node *before = Head;
        for (int i = 0; i<pos-2; i++)
            before = before->Next;
 
        pnew->Next = before->Next;
        before->Next = pnew;
        size++;
    }
 
    void Print ()
    {   Node *p = Head;
        while (p != NULL)
        {   cout << p->x << ' ';
            p = p->Next;
        }
        cout << endl;
    }
};
 
int main()
{   List lst;
    setlocale(LC_ALL, "RUSSIAN");
    int a, pos;
    int counter=0;
	cout<<"Введите 10 элементов списка через enter: \n";
	for(int j=0; j<10; j++)
	{
		cin>>a;
		lst.PushBack(a);
			counter++;
	}
	pos=(counter/2)+1;
 
    lst.Print();
    cout << "Введите значение элемента для вставки:\n";
    cin >> a;
 
    lst.Insert(a, pos);
    lst.Print();
    
    cin.sync(); cin.get();
    return 0;
}