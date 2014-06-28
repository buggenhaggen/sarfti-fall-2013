#include <iostream>

using namespace std;


struct STACK{
	int m[80];int sz;
}; 


//stack push
void s_push(STACK &s, int n){
		s.m[s.sz++] = n;
}

//is empty stack
int isemp_s(STACK& s){
	if(s.sz <= 0)
		return 1;
	else return 0;
}


void srt(int *A, int N){

    if (! N) return;

    for (int i = 1; i < N; i++)

        for (int j = i; j && A[j] < A[j-1]; j--)

            swap(A[j], A[j-1]);
}

//stack pop
int s_pop(STACK &s){
	if(s.sz <= 0){
			return 0;
	}
	else{
		return s.m[--s.sz];
	}
}


void main()
{
	STACK stack;
	stack.sz = 0;
	cout<<"STACK REALIZATION\n"<<endl<<endl;

	//stack_adding
	for(int index = 0;	index<10;		index++){
			s_push(stack,rand()%1234);			  }

	//stack_sorting

	int m[10];

	int index = 0;

	while(!isemp_s(stack)){
			m[index++] = s_pop(stack);
	}

	srt(m, index);

	for(int i = index-1; i>=0 ; i--){
		s_push(stack,m[i]);			}

	cout<<"STACK after sorting\n"<<endl;

	while(!isemp_s(stack)){
					cout<<s_pop(stack)<<" ";
	}

	cout<<endl;

}