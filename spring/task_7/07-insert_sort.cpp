#include <iostream>
using namespace std;

int i,j;

//insert sort
void isort(int *M, int s);

void main(){
	int a[10];
	int s = 10;

	//create and out array
	for(i = 0; i<s ;i++){
		a[i] = rand()%307;	cout<<a[i]<<" ";
	}
	cout<<endl;
	//sort
	isort(a,10);

	//after sort
	for(i = 0; i<s ;i++){
		cout<<a[i]<<" ";
	}

	cout<<endl;
}

void isort(int *M, int s){
    for (i = 1; i < s; i++)
        for (int j = i; j; j--)
			if(M[j] < M[j-1])
				swap(M[j], M[j-1]);
}