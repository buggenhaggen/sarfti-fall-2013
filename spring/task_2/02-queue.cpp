#include <iostream>
using namespace std;

struct QUEUE{
	int* f;int* l;
};

void ins_q(QUEUE &queue, int val);

void g_frst500(QUEUE &queue, int *m);

void main(){
	QUEUE queue;
	int M[100000];

	int gM[500];

	queue.f  = M;
	queue.l = M - 1;

	cout<<"QUEUE REALIZATION:\n\n";

	//insert to queue
	for(int i = 0; i<3000; i++){
		ins_q(queue,5000-i);
	}

	//get first 500 els
	g_frst500(queue,gM);

	//out only 30
	cout<<"first 30 elements from queue:\n";
	for(int i = 0; i< 30; i++){
		cout<<gM[i]<<" ";	  }
	cout<<endl;

}


void ins_q(QUEUE &queue, int val){
	queue.l = queue.l+1;
	*(queue.l) = val;
}

void g_frst500(QUEUE &queue, int *m){
	for(int i = 0; i<500; i++){
		m[i] = *queue.f;
		queue.f ++;
	}
}