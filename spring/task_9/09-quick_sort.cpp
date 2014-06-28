#include <iostream>
using namespace std;

//quick sort
void qs(int* M, int ft, int lt);

void main()
{
	int M[20];
	cout<<"QUICK SORT REALIZATION:\n\n";
	cout<<"before sort:\n";
	for(int i = 0; i<20; i++)
	{
		M[i] = rand()%747;
		cout<<M[i]<<" ";
	}
	cout<<endl;
	qs(M,0,19);
	cout<<"after sort:\n";
	for(int i = 0; i<20 ;i++)
	{
		cout<<M[i]<<" ";
	}
	cout<<endl;
}

void qs(int* M, int ft, int lt){
    int i = ft, j = lt, x = M[(ft + lt) / 2];
    do {
        while (M[i] < x) i++;
        while (M[j] > x) j--;
        if(i <= j) {
            if (i < j) swap(M[i], M[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < lt)
        qs(M, i, lt);
    if (ft < j)
        qs(M, ft,j);
}