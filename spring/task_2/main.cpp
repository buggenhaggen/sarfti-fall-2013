#include "queue.h"
#include <iostream>
#include <conio.h>
using namespace std;
 
int main()
{
	setlocale(LC_ALL,"Russian");
    queue q;
    q.init();
	cout<<"�������� �������: \n";
	for(int n=0; n<=502; n++)//����� ������� ���������� 502 ���a, ����� ��������� �������. ������� ����������� �� 1 ��������
	{
    q.put(n);
	}
	cout<<"\n";
    q.get();//�� ������� ����������� ����� 500 ���������
	getch();
}