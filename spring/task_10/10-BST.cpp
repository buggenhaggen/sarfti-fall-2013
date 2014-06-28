#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

struct ND{
  int v;
  struct ND * lv;
  struct ND * rv;
};

struct TR{
  struct ND * root;
  int cnt;		
};

struct TR * TR_cr(void);

int TR_src(const struct TR * sTR, int it);
int in_ND(struct TR * sTR, int it);//insert node
static void out(const struct ND * sND);
void f_out(const struct TR * sTR);//full out
struct ND * TR_max(struct TR * sTR);//tree max
int d_ND(struct TR * sTR, int ** it);//del node


void main(){
	cout << "BST REALIZATION\n";
	TR* sTR;
	sTR = TR_cr();

	int st;
	for(int i = 0; i<50 ;i++){
		st = in_ND(sTR,rand()%102);
	}
	cout<<"tree out\n";
	f_out(sTR);
	cout<<endl;
	int rez_search;
	rez_search = TR_src(sTR,60);
	if(rez_search == 0)	cout<<"num 60 not fnd\n";
	else cout<<"60 fnd\n";

	//max node
	ND* mxND = TR_max(sTR);

	cout<<"max value is "<<mxND->v<<endl;

	int rez_del;

	rez_del = d_ND(sTR, (int**) mxND->v);
	f_out(sTR);
}


struct TR * TR_cr(void){
	struct TR * n_TR = (TR*) malloc(sizeof * n_TR);
	if (n_TR == NULL) return NULL;
	n_TR->root = NULL;
	n_TR->cnt = 0;
	return n_TR;
}

int TR_src(const struct TR * sTR, int it){
  const struct ND * sND;
  sND = sTR->root;
	for(;;)
	{
		if (sND == NULL) return 0;
		else if (it == sND->v) return 1;
		else if (it > sND->v) sND = sND->rv;  
		else sND = sND->lv;  
	}
}

//insert node
int in_ND(struct TR * sTR, int it){
	struct ND * sND, **new_el;

	new_el = &sTR->root;
	sND = sTR->root;

	for(;;){
		if(sND == NULL){
			sND = *new_el = (ND*)malloc(sizeof * sND);
			if(sND != NULL){
				sND->v = it;
				sND->lv = sND->rv=NULL;
				sTR->cnt++;
				return 1;
			}
			else return 0;
		}
		else if(it == sND->v) return 2;
	else if(it > sND->v){
	new_el = &sND->rv;
	sND = sND->rv;
		}
		else{
			new_el = &sND->lv;
			sND = sND->lv;
		}
	}
}


static void out(const struct ND * sND){
	if(sND == NULL) return;
	out(sND->lv);
	printf("%d ", sND->v);
	out(sND->rv);
}	

void f_out(const struct TR * sTR){
	out(sTR->root);
}


struct ND * TR_max(struct TR * sTR){
	struct ND * sND;
	sND = sTR->root;
	while (sND->rv != NULL)
			sND = sND->rv;
	return sND;
}


int d_ND(struct TR * sTR, int ** it){
	struct ND ** q,*z;
	q=&sTR->root;
	z=sTR->root;
	for(;;){
		if(z == NULL) return 0;
		else if(it == (int **)z->v) break;
		else if(it > (int **)z->v){
			q = &z->rv;
			z = z->rv;
		}
		else{
			q = &z->lv;
			z = z->lv;
		}
	}		
	
	if(z->rv == NULL) *q = z->lv;
	else{
		struct ND * y = z->rv;
		if(y->lv == NULL){
			y->lv = z->lv;
			*q-y;
		}
		else{
			struct ND * x=y->lv;
			while(x->lv != NULL){
				y = x;
				x = y->lv;
			}
			y->lv = x->rv;
			x->lv = z->lv;
			x->rv = z->rv;
			*q=x;
		}
	}

	sTR->cnt --;
	free(z);
	return 1;
}