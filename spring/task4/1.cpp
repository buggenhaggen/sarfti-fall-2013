#include "List.h"
int main()
{
	////��������� ������� � ������������ ����������:
	setlocale(LC_ALL, "Russian");
	//�������������� ������
	srand((unsigned)time( NULL )); 
	do 
	{
		cout<<"������� ���������� ��������� ������: ";
		int count;
		cin>>count;
		MyList initial_list;
		for (int i = 0; i < count; i++)
		{
			//��������� ������ ���������� �� 0 �� 100
			initial_list.Add(rand()%100);
		}
		cout<<"����������� ������: \n";
		ListIterator p = initial_list.Begin();
		int i = 0;
		while (i < initial_list.GetCount())
		{
			cout<<*p<<" ";
			p++;
			i++;
		}
		p = initial_list.LastItem();
		i = 0;
		cout<<endl<<"������ � �������� �������: \n";
		while (i < initial_list.GetCount())
		{
			cout<<*p<<" ";
			p--;
			i++;
		}
		cout<<endl;
	} while (_getch() != 27);
	
	return 0;
}
