#include <iostream>
using namespace std;

void Merge(int *A, int first, int last)
{
	int middle, start, final, j;
	int *mas=new int[100];
	middle=(first+last)/2; //���������� �������� ��������
	start=first; //������ ����� �����
	final=middle+1; //������ ������ �����
	for(j=first; j<=last; j++) //��������� �� ������ �� �����
	{
		if ((start<=middle) && ((final>last) || (A[start]<A[final])))
		{
			 mas[j]=A[start];
			 start++;
		}
		else
		{
			 mas[j]=A[final];
			 final++;
		}
	}
	//����������� ���������� � ������
	for (j=first; j<=last; j++) A[j]=mas[j];
	delete[]mas;
};


//����������� ��������� ����������
void MergeSort(int *A, int first, int last)
{
	if (first<last)
		{
			 MergeSort(A, first, (first+last)/2); //���������� ����� �����
			 MergeSort(A, (first+last)/2+1, last); //���������� ������ �����
			 Merge(A, first, last); //������� ���� ������
		}
};



void main()
{
	int mas[20];

	cout<<"MERGE SORT:\n\n";
	cout<<"source massive:\n";

	for(int i = 0; i<20; i++)
	{
		mas[i] = rand()%200;	//�������� ��������������� ������
		cout<<mas[i]<<" ";
	}

	cout<<endl;

	MergeSort(mas,0,19);	//������� ���������� ��������

	cout<<"sorted massive:\n";

	for(int i = 0; i<20 ;i++)
	{
		cout<<mas[i]<<" ";	//����� ���������������� �������
	}

	cout<<endl;

}