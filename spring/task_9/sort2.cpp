
#include <iostream>
#include <conio.h>

using namespace std;

class S
{
public:
void Sort(int* A, int b, int c)// сортировка
{
	
int x = A[b + (c - b) / 2];
    int i = b;
    int j = c;
    while(i <= j)
    {
        while(A[i] < x) i++;
        while(A[j] > x) j--;
        if(i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (i<c)
                Sort( A, i, c);
    
    if (b<j)    
        Sort( A, b, j);    
};
};
//главная функция
void main()
{
	S obj;
setlocale(LC_ALL, "Rus");
int i, n;
int *A=new int[100];
cout<<"Введите размер массива  "; 
cin>>n;
cout<<"Массив: ";
for (int i=1; i<=n; i++)
{
	A[i]=0+rand()%100;
	cout<<A[i]<<" ";
}
cout<<"\n";
obj.Sort(A, 0, n-1); 
cout<<"Отсортированный массив: "; 
for (i=1; i<=n; i++)
{
	cout<<A[i]<<" ";
}
getch();
}