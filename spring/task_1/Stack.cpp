#include <iostream>
#include <stack>
#include <time.h>
#include <queue>
using namespace std;

int main()
{
	//������������� ��������� ������� �������
	setlocale(LC_ALL, "Russian");
	stack<int> base, sorted;
	int n;
	cout<<"������� ���������� ��-�� �����: ";
	cin>>n;
	//�������������� ������
	srand((unsigned)time( NULL )); 
	cout<<"�������� ����:"<<endl;
	for (int  i = 0; i < n; i++ )
	{
		//�������� �������� ���� ���������� ���������� �� ��������� [0; 100] 
		int value = (double)rand() / (RAND_MAX + 1) * 100;
		cout<<value<<"; ";
		base.push(value);		
	}
	cout<<endl;
	while (!base.empty())
	{	
		if (sorted.empty())//���� ������������� ���� ������ ��������� � ���� ������� ������� ��������� �����
		{
			sorted.push(base.top());
			base.pop();
		}
		else
		{
			if (base.top() <= sorted.top())//���� ������� ��-� ���������������� ����� >=  �������� ������� ��������� ����� ��������� � ���� ������� ������� ��������� �����
			{
				sorted.push(base.top());
				base.pop();
			}
			else//����� ��������� �������� �������� ��-�� ��������� ����� � ���������� � ���������� �� ���������������� ��-�� ���� ������� ��-� ���������������� ����� �� ����� >= ������������ ��������
			{
				int ini_top = base.top();
				base.pop();
				while(ini_top > sorted.top())//���������� ������� ������� ������������ ����� � ������� ���������������� 
				{
					base.push(sorted.top());
					sorted.pop();
					if(sorted.empty())//������� �� ����� ���� ��������������� ���� ����
						break;
				}
				sorted.push(ini_top);
			}
		}		
	}	
	cout<<"��������������� ����:"<<endl;
	while(!sorted.empty())
	{
		cout<<sorted.top()<<"; ";
		sorted.pop();	
	}	
	cout<<endl;
	return 0;
}