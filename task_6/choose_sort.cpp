#include <iostream>
using namespace std;


void exch(int& a, int& b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;

}

void main()
{
	int a[10];
	int len = 10;

	cout<<"CHOOSE SORT:\n\n";
	cout<<"source massive:\n";

	for(int i = 0; i<len ;i++)
	{
		a[i] = rand()%209;
		cout<<a[i]<<" ";
	}

	cout<<endl;

	//����������

	/* ������� ����. i � ������� ������� ������������������ �������� �� ������ �������� */
    for (int i = 0; i < len - 1; i++) {
        int min = i; /* min � ������� ������������ �������� */
 
        /* ���������� ����. ���� ������ ������� ������ ������� �������� ������������, ���������� ��� ������ ��� ����������� */
        for(int j = i + 1; j < len; j++) {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i) /* ����������� ������� �� �������� ������ �����������������, ����� ����� */
            exch(a[i], a[min]);
    }


	cout<<"sorted massive:\n";
	for(int i = 0; i<len ;i++)
	{
		cout<<a[i]<<" ";
	}

	cout<<endl;

}


	
