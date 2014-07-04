#include <iostream>
#include <stack>
#include <time.h>

using namespace std;
stack<int> SortStack(stack<int> initial);
int main()
{
	//�������������� ������
	srand((unsigned)time( NULL )); 
	//������������� ��������� ������� �������
	setlocale(LC_ALL, "Russian");
	stack<int> initial;
	int count;
	cout<<"������� ���������� ��������� �����: ";
	cin>>count;	
	cout<<"�������� ����"<<endl;
	int i = 0;
	while(i < count)
	{
	//�������� ���� ���������� ������� �� 0 �� 100
		int value = rand()%100;
		cout<<value<<" ";
		initial.push(value);
		i++;
	}
	initial = SortStack(initial);
	cout<<endl;
	cout<<"��������������� ����"<<endl;
	while(!initial.empty())
	{
		cout<<initial.top()<<" ";
		initial.pop();	
	}	
	cout<<endl;
	return 0;
}
//������� ����������
stack<int> SortStack(stack<int> initial)
{
	stack<int> sort;
	while (!initial.empty())
	{	
		if (sort.empty())//���� ������������� ���� ������ ������ � ���� ������� ������� ����������� �����
		{
			sort.push(initial.top());
			initial.pop();
		}
		else
		{
			if (initial.top() <= sort.top())//���� ������� ��-� ���������������� ����� >=  �������� ������� ��������� ����� ��������� � ���� ������� ������� ��������� �����
			{
				sort.push(initial.top());
				initial.pop();
			}
			else//��������� �������� �������� ��-�� ��������� ����� � ���������� � ���������� �� ���������������� ��-�� ���� ������� ��-� ���������������� ����� �� ����� >= ������������ ��������
			{
				int ini_top = initial.top();
				initial.pop();
				while(ini_top > sort.top())
				{
					initial.push(sort.top());
					sort.pop();
					if(sort.empty())//������� �� ����� ���� ��������������� ���� ����
						break;
				}
				sort.push(ini_top);
			}
		}		
	}	
	return sort;
}