//���������� ��������� ���������� ����� �� �����������

#include "conio.h"
#include "iostream"
#include "stack"
 
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
 
    stack<int> original;//������ ���� 
    stack<int> auxiliary;//������ ��������������� ����
    
    int i;//������ ����������
    cout <<"������ ����: \n";
    for(int i = 5; i >= 0; --i) //��������� ������ ���� ���������� ����������
    {
        original.push(rand()%21);
        cout << original.top() << " ";//������� �������� ������ �������� ��������
    }
 
    cout <<"\n";
    int m;//������ ����������
    for(i=0;i<5;i++)
{
	m=original.top();//����������� m �������� �������� ��������
	original.pop();//������� ��� �� �����
	while(!original.empty())//���� ������ ���� �� ��������
	{
		if(m<original.top())
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
    cout << "��������� ���������� �����: \n";//����� ����������
    while(!original.empty()) {
        cout << original.top() << " ";
        original.pop();
    }
        
    getch();
}