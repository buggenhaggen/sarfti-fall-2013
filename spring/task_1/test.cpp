// ���� ���� �� ����-��������� ������� ������� ������� ����� � ������� ���� �� �����. ���� ���� ����- ��������� �����������
#include "conio.h"
#include "iostream"
#include "stack"

using namespace std;
class S
{
public:
	stack<int> original;//������ ���� 
    stack<int> auxiliary;//������ ��������������� ����
    
    int i;//������ ����������
    int m;//������ ����������
	void set(int x)
	{
		for(i=0;i<x;i++) 
		{
          original.push(rand()%100);
          cout << original.top() << " ";
		}
 
    cout <<"\n";
	};
	void p(int x)
	{
		original.pop();

		if(x!=0)
		{
			cout<<"c��� ��� �������� ��������:  ";
			for(i=0;i<(x-1);i++) //������������ ����, ������ �������������� ������� �������("��������� �����-������ �����")
				{
					int m=original.top();
					cout<<m<<" ";
					original.pop();
				}
		}
	};
};

int main()
{
    setlocale(LC_ALL,"Russian");
	S obj;
	cout<<"������� ����� ��������� � �����: ";
	int x;
	cin>>x;
	cout<<"\n";
	if(x!=0)
	{
	cout <<"����: ";
	obj.set(x);
	}
	obj.p(x);        
    getch();
}