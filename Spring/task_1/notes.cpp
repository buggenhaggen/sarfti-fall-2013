#include <iostream>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

void Out(stack<int> cur_stack)
{
	int i = 1;
	while(!cur_stack.empty())
	{
		cout<<i<<":\t"<<cur_stack.top()<<endl;
		cur_stack.pop();
		i++;
	}
}
stack<int> sort(stack<int> initial)
{
	stack<int> sorted;	
	while (!initial.empty())
	{	
		if (sorted.empty())//���� ������������� ���� ������ ��������� � ���� ������� ������� ��������� �����
		{
			sorted.push(initial.top());
			initial.pop();
		}
		else
		{
			if (initial.top() <= sorted.top())//���� ������� ��-� ���������������� ����� >=  �������� ������� ��������� ����� ��������� � ���� ������� ������� ��������� �����
			{
				sorted.push(initial.top());
				initial.pop();
			}
			else//����� ��������� �������� �������� ��-�� ��������� ����� � ���������� � ���������� �� ���������������� ��-�� ���� ������� ��-� ���������������� ����� �� ����� >= ������������ ��������
			{
				int ini_top = initial.top();
				initial.pop();
				while(ini_top > sorted.top())//���������� ������� ������� ������������ ����� � ������� ���������������� 
				{
					initial.push(sorted.top());
					sorted.pop();
					if(sorted.empty())//������� �� ����� ���� ��������������� ���� ����
						break;
				}
				sorted.push(ini_top);
			}
		}		
	}
	return sorted;
}
int main()
{
	//������������� ��������� ������� �������
	setlocale(LC_ALL, "Russian");
	stack<int> initial, sorted;
	int n;
	cout<<"������� ���������� ��-�� �����: ";
	cin>>n;
	//�������������� ������
	srand((unsigned)time( NULL )); 
	for (int  i = 0; i < n; i++ )
	{
		//�������� �������� ���� ���������� ���������� �� ��������� [-1000; 1000] 
		initial.push((double)rand() / (RAND_MAX + 1) * (1000 - (-1000))	+ (-1000));		
	}
	cout<<"�������� ����:"<<endl;
	Out(initial);
	sorted = sort(initial);
	cout<<"��������������� ����:"<<endl;
	Out(sorted);	
	return 0;
}