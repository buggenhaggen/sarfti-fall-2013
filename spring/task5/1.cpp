#include "Tree.h"
using namespace std;


// ������ ������������� ������:
int main()
{
	////��������� ������� � ������������ ����������: 
	//if(SetConsoleCP(1251)==0)
	////�������� ������������ ��������� ��������� �������� ��� �����
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//}
	//if(SetConsoleOutputCP(1251)==0)//���� ����� ��� ������
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}
	setlocale(LC_ALL, "Russian");
	Tree tree; // ��������� ������ ��������� ������
	Tree nechet, chet; //��� ������ ������ � �������� 
	int x;
// ��������� ���� � �������:
	ifstream file("numbers.txt");
	if (file)
	{
		bool f_first = true;
		cout << "��������� ������������������: \n";
		do
		{
			file>>x;
			if (!file.eof())
			{
				cout << x << " ";
				if (f_first)
				{
					tree.Add(x); // ��������� ������ ������� ��� ������ ������
					f_first = false;					
				}
				else
				{
					//�������� �������� ������ � �������� �������
					if (x%2)//��������
					{
						nechet.Add(x);
					}
					else
						chet.Add(x);
				}
				
			}
		} while (!file.eof());
		cout<<endl;
		//��������� � ��������� �������� ������ ����� � ������ ����������
		tree.rootPtr->lPtr = nechet.rootPtr;
		tree.rootPtr->rPtr = chet.rootPtr;
		cout<<"����� ������ (������ ����������� ����� �������):"<<endl;
		tree.Out();
	}
	else cout << "���� �� ������\n";
	_getch();
	return 0;
}
