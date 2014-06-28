#include <iostream>
using namespace std;


//merge sorting
void Mg(int *M, int fst, int lt);
void Mg_rec(int *M, int fst, int lt);

void main(){
	int M[33];

	cout<<"MERGE SORT REALIZATION:\n\n";
	cout<<"before sort:\n";

	for(int i = 0; i<30; i++){
		M[i] = rand()%543;
		cout<<M[i]<<" ";
	}
	cout<<endl;
	//sort
	Mg_rec(M,0,29);
	cout<<"sorted massive:\n";
	for(int i = 0; i<30 ;i++){
		cout<<M[i]<<" ";
	}
	cout<<endl;
}


void Mg(int *M, int fst, int lt){
	int mid, st, fin, j;
	int *mas=new int[100];
	mid=(fst+lt)/2; 
	st=fst;
	fin=mid+1;
	for(j=fst; j<=lt; j++){
		if ((st<=mid) && ((fin>lt) || (M[st]<M[fin]))){
			 mas[j]=M[st];
			 st++;
		}
		else{
			 mas[j]=M[fin];
			 fin++;
		}
	}
	for (j=fst; j<=lt; j++) M[j]=mas[j];
};



void Mg_rec(int *M, int fst, int lt){
	if (fst<lt){
			 Mg_rec(M, fst, (fst+lt)/2);
			 Mg_rec(M, (fst+lt)/2+1, lt);
			 Mg(M, fst, lt);
		}
};