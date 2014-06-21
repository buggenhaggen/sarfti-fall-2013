#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void Sort(int arr[], int size);
 
int main()
{
	const int size=10;
	int arr[size];
	for(int i=0;i<size;++i)
	arr[i]=1+rand()%100-1+1;
	cout<<"arr is:\n";
	for( i=0;i<size;++i) cout<<arr[i]<<' ';
	cout<<endl;
	Sort(arr,size);
	cout<<"Sorted array:\n";
	for( i=0;i<size;++i) cout<< arr[i] <<' ';
	cout<<endl;
	return 0;
}
 
void Sort(int arr[],int size)
{
	for(int i=1;i<size;++i)
		for(int j=i;j>0&&arr[j-1]>arr[j];--j)
			swap(arr[j-1],arr[j]);
}