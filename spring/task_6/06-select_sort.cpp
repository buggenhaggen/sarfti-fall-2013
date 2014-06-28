#include <iostream>
using namespace std;


void ssort(int* M, int s);

void main(){
	int M[10];
	int s = 10;

	cout<<"SELECT SORT REALIZATION:\n\n";
	cout<<"before sort:\n";

	for(int i = 0; i<s ;i++)
	{
		M[i] = rand()%443;
		cout<<M[i]<<" ";
	}
	cout<<endl;

	//select sorting
	ssort(M,s);
	cout<<"after sort:\n";
	for(int i = 0; i<s ;i++){
		cout<<M[i]<<" ";
	}
	cout<<endl;
}

void ssort(int* M, int s){
    for (int i = 0; i < s - 1; i++) {
        int m = i;
        for(int j = i + 1; j < s; j++) {
            if(M[j] < M[m])
                m = j;
        }
        if(m != i)
            swap(M[i], M[m]);
    }
}



	
