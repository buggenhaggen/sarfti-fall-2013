#include <iostream>
using namespace std;


//������� ���������� ���������
void InsertionSort(int *A, int N)
{
    if (! N) return;
 
    for (int i = 1; i < N; i++)
        for (int j = i; j && A[j] < A[j-1]; j--)
            swap(A[j], A[j-1]);
}


void main()
{
	int a[10];
	int len = 10;

	//������� ��������� ������
	for(int i = 0; i<len ;i++)
	{
		a[i] = 16-i;
		cout<<a[i]<<" ";
	}

	cout<<endl;

	//���������
	InsertionSort(a,10);

	for(int i = 0; i<len ;i++)
	{
		cout<<a[i]<<" ";
	}

	cout<<endl;
}