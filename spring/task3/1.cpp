#include "List.h"
using namespace std;
int main()
{
	////��������� ������� � ������������ ����������: 
	setlocale(LC_ALL, "Russian");
	//�������������� ������
	srand((unsigned)time( NULL )); 
	cout<<"������� ���������� ��������� ������: ";
	int count;
	cin>>count;
	MyList initial_list;
	for (int i = 0; i < count; i++)
	{
		//��������� ������ ���������� �� 0 �� 100
		initial_list.Add(rand()%100);
	}
	do
	{
		cout<<"����������� ������: \n";
		cout << initial_list;
		cout<<"������� �����: ";
		int val;
		cin>>val;
		initial_list.AddToListCenter(val);
		cout<<"���������� ������: \n";
		cout << initial_list;
	} while (_getch() != 27);
	return 0;
}
