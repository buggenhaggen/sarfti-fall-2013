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
		for(i=0;i<x;i++) //��������� ������ ���� ���������� ����������
		{
          original.push(rand()%100);
          cout << original.top() << " ";//������� �������� ������ �������� ��������
		}
 
    cout <<"\n";
	};
	void sort(int x)
	{
		for(i=0;i<x;i++)
		{
			m=original.top();//����������� m �������� �������� ��������
			original.pop();//������� ��� �� �����
			while(!original.empty())//���� ������ ���� �� ��������
			{
				if(m<=original.top())
				{
					auxiliary.push(m);//���� m ������ ���������� �������� �����, ��������� ��� � ���������������� �����
					m=original.top();
					original.pop();
				}
				else//���� m ������...
				{
					auxiliary.push(original.top());
					original.pop();
				}
			}
			original.push(m);
			while(!auxiliary.empty())//���� �� �������� ��������������� ����
			{
				original.push(auxiliary.top());//������������ �������� � ��������
				auxiliary.pop();
			}
		}
		while(!original.empty()) 
		{
			cout << original.top() << " ";
			original.pop();
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
		if(x<=0)
		{
			cout<<"����� ������ ���� ������ ���� \n";
		}
		else
		{
		cout<<"\n";
		cout <<"������ ����: ";
		obj.set(x);
		cout << "��������� ���������� �����: ";//����� ����������
		obj.sort(x);
		}
		 getch();
		 return 0;

	}