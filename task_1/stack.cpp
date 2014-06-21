#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_SIZE 35


struct stack
{
	int mas[40];
	int size;
}; 



void push(stack &s, int n);
int pop(stack &s);
int isemp(stack& s);


void InsertionSort(int *A, int N)
{
    if (! N) return;
 
    for (int i = 1; i < N; i++)
        for (int j = i; j && A[j] < A[j-1]; j--)
            swap(A[j], A[j-1]);
}


void main()
{
	stack s1;
	stack s2;

	s1.size = 0;
	s2.size = 0;

	cout<<"STACK\n"<<endl<<endl;

	//заполнение стека некоторыми числами
	push(s1,3);
	push(s1,5);
	push(s1,4);
	push(s1,1);
	push(s1,2);

	//сортировка стека

	int mas[10];
	int ind = 0;

	while(!isemp(s1))
	{
		mas[ind++] = pop(s1);
	}

	InsertionSort(mas, ind);

	for(int i = ind-1; i>=0 ; i--)
		push(s1,mas[i]);

	//Вывод стека после сортировки

	cout<<"stack after sorting\n"<<endl;

	while(!isemp(s1))
	{
		cout<<pop(s1)<<" ";
	}

	cout<<endl;

}


void push(stack &s, int n)
{
		s.mas[s.size++] = n;
}



int pop(stack &s)
{
	if(s.size <= 0)
	{
		printf("Stack is EMPTY\n");
		return 0;
	}
	else
	{
		return s.mas[--s.size];
	}
}


int isemp(stack& s)
{
	if(s.size <= 0)
		return 1;
	else return 0;
}