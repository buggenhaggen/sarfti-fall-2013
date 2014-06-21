#include <iostream.h>
#include <stdlib.h>
 
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
	int pos;
	int tmp;
	for(int i=0;i<size;++i)
	{
		pos=i;
		tmp=arr[i];
		for(int j=i+1;j<size;++j)
			if (arr[j]<tmp)
			{
				pos=j;
				tmp=arr[j];
			}
		arr[pos]=arr[i];
		arr[i]=tmp;
		if(size>1) Sort(arr,(size-1));
	}
}