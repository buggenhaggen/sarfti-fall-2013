#include <iostream>
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

struct TR * Tr_cr(void);
int Ins_ND(struct TR * s_TR, int it);
static void out(const struct ND * s_ND);
void f_out(const struct TR * my_tree);

void main(){
	TR* s_TR; 
	s_TR = Tr_cr();
	cout << "ROOT TREE\n";
	s_TR -> root = (ND*)malloc(sizeof ND);
	s_TR -> root ->v = 0;
	s_TR -> root ->lv = NULL;
	s_TR -> root ->rv = NULL;

	int st;

	//add els to tree
	for(int i = 0; i<50 ;i++){
		st = Ins_ND(s_TR,rand()%60);
	}
	cout<<"tree out\n";
	//tree out
	f_out(s_TR);
	cout<<endl;
}

struct TR * Tr_cr(void)	{
	struct TR * n_tr = (TR*) malloc(sizeof * n_tr);
	if (n_tr == NULL) return NULL;
	n_tr->root = NULL;
	n_tr->cnt = 0;
	return n_tr;
}

static void out(const struct ND * s_ND){
	if(s_ND == NULL) return;
	out(s_ND->lv);
	printf("%d ", s_ND->v);
	out(s_ND->rv);
}	


void f_out(const struct TR * my_tree){
	out(my_tree->root);
}

int Ins_ND(struct TR * s_TR, int it){
	struct ND * s_ND, **new_el;

	if(it%2 == 1){
		//s_TR->root->lv = (ND*)malloc(sizeof ND);
		new_el = &s_TR->root->lv;
		s_ND = s_TR->root->lv;
	}

	else{
		//s_TR->root->rv = (ND*)malloc(sizeof ND);
		new_el = &s_TR->root->rv;
		s_ND = s_TR->root->rv;
	}


	while(1){
		if(s_ND == NULL){
			s_ND = *new_el = (ND*)malloc(sizeof * s_ND);
			if(s_ND != NULL){
				s_ND->v = it;
				s_ND->lv = s_ND->rv=NULL;
				s_TR->cnt++;
				return 1;
			}
			else return 0;
		}
		else if(it == s_ND->v) return 2;
	else if(it > s_ND->v){
	new_el = &s_ND->rv;
	s_ND = s_ND->rv;
		}
		else{
			new_el = &s_ND->lv;
			s_ND = s_ND->lv;
		}
	}
}