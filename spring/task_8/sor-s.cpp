#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void Sort(int *A,int f,int l);
void M(int *A,int f,int l);
 
int main()
{
	const int size=10;
	int A[size];
	for(int i=0;i<size;++i)
	A[i]=rand()%100;
	cout<<"arr is:\n";
	for( i=0;i<size;++i) cout<<A[i]<<' ';
	cout<<endl;
	Sort(A,0,size);
	cout<<"Sorted array:\n";
	for( i=0;i<size;++i) cout<<A[i] <<' ';
	cout<<endl;
	return 0;
}
 
void Sort(int *A,int f,int l)
{
	if (f<l)
	{
		Sort(A,f,(f+l)/2);
		Sort(A,(f+l)/2+1,l);
		M(A,f,l);
	}
}

void M(int *A,int f,int l)
{
	int mid,start,fin,j;
	int *mas=new int[100];
	mid=(f+l)/2;
	start=f;
	fin=mid+1;
	for(j=f;j<=l;j++)
	{
		if ((start<=mid)&&((fin>l)||(A[start]<A[fin]))) mas[j]=A[start++];
		else mas[j]=A[fin++];
	}

	for(j=f;j<=l;j++) A[j]=mas[j];
	delete[]mas;
}