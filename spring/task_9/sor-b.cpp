#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Sort(int* A, int b, int c);
 
int main()
{
	int arr[1000],size;
	cout<<"input size: ";
	cin>>size;
	for(int i=0;i<size;++i)
	arr[i]=1+rand()%100-1+1;
	cout<<"arr is:\n";
	for( i=0;i<size;++i) cout<<arr[i]<<' ';
	cout<<endl;
	Sort(arr,0,size-1);
	cout<<"Sorted array:\n";
	for( i=0;i<size;++i) cout<< arr[i] <<' ';
	cout<<endl;
	return 0;
}
 
void Sort(int* arr,int f,int s)
{
	int x=arr[f+(s-f)/2],i=f,j=s;
    while(i<=j)
    {
        while(arr[i]<x) ++i;
        while(arr[j]>x) --j;
        if(i<=j) swap(arr[i++],arr[j--]);
    }
    if(i<s) Sort(arr,i,s);
    if(f<j) Sort(arr,f,j); 
}