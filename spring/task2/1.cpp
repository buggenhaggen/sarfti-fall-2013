#include "Queue.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////
int main()
{
	//��������� ��������� ������� �������
	setlocale(LC_ALL, "Russian");
	Queue queue;
	int count;
	//�������������� ��������� 
	srand((unsigned)time( NULL )); 
	do
	{
		cout<<"������� ���������� ��������� ������� ";
		cin>>count;
		int i = 0;
		while(i < count)
		{
			//�������� �������� ���� ���������� ���������� �� 0 �� 100
			queue.push(rand()%100);	
			i++;
		}
		cout<<"�������� �������:\n"<<queue;
		queue.pop_first_500();//������� 500 ��-�� � ������ �������
		cout<<"���������� ��������: \n"<<queue;
	} while (_getch() != 27);
	return 0;
}

