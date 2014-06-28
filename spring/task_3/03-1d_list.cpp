#include <iostream>
using namespace std;

//l element
struct L_elem{
	int v;
	L_elem* nx;
};


//l main structire
struct List{
	L_elem* ft;	 
	L_elem* fl;
	int sz;
	int cnt;
};

int ne(List &l);
void fe(List &l);
int ge(List &l);
void se(List &l, int v);
void ie(L_elem* el_ptr, List &l, int v);

void main(){
	L_elem l[1000];
	List lstr;
	lstr.ft = l;
	lstr.fl = lstr.ft;
	lstr.cnt = 0;
	lstr.sz = 0;

	cout<<"SINGLY LINKER LIST REALIZATION:\n\n";

	//add numb to list

	for(int i = 0; i< 10; i++){
		se(lstr,50-i);
		ne(lstr);
		lstr.sz++;
	}
	fe(lstr);

	//list out

	cout<<"list out:\n";

	while(lstr.cnt <= lstr.sz){
		cout<<ge(lstr)<<" ";
		ne(lstr);
	}
	cout<<endl;
	//middle find

	int mdl = lstr.sz/2;
	fe(lstr);

	for(int i = 0; i<mdl; i++){
		ne(lstr);
	}
	L_elem b;
	ie(&b, lstr, 200);	//insert to middle
	fe(lstr);

	cout<<"after past:\n";

	while(lstr.cnt <= lstr.sz){
		cout<<ge(lstr)<<" ";
		ne(lstr);
	}
	cout<<endl;

}


//next element
int ne(List &l){
	if((l.fl->nx) == NULL){
		printf("Last Element is Achived\n");
		return 1;
	}
		
	else{
		l.fl = l.fl->nx;
		l.cnt++;
		return 0;
	}
}


//first element
void fe(List &l){
	l.fl = l.ft;
	l.cnt = 1;
}

int ge(List &l){
	return l.fl->v;
}


void se(List &l, int v){
	l.fl->v = v;
	l.fl->nx = l.fl + 1;
}


void ie(L_elem* el_ptr, List &l, int v){
	el_ptr->nx = l.fl->nx;
	l.fl->nx = el_ptr;
	el_ptr->v = v;

	l.sz++;
	l.cnt++;
}