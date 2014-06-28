#include <iostream>
using namespace std;

struct Le{
	int v;
	Le* pv;	Le* nx;
};

struct List{
	Le* ft;	Le* fl;
	int sz;	int cnt;
};

//iterator class
class I2L{
	Le* el;
	List* list;

	public:

		I2L(List* list){
			this->list = list;
			this->el = list->ft;
		}
		void beg(){
			list->cnt = 1;
		}
		int gtv(){
			return this->list->fl->v;
		}
		void gb(){
			list->fl = list->fl->pv;
			list->cnt--;
		}
		void gf(){
			list->fl = list->fl->nx;
			list->cnt++;
		}
		void se(int v){
			list->fl->nx = list->fl + 1;
			list->fl->pv = list->fl - 1;
			list->fl->v = v;
		}
};


void main(){
	Le list[200];
	List lstr;
	lstr.ft = list;
	lstr.fl = lstr.ft;
	lstr.cnt = 0;
	lstr.sz = 0;
	cout<<"DOUBLE LINKER LIST REALIZATION:\n\n";

	I2L iter(&lstr);

	//add numbs to list

	for(int i = 0; i < 5; i++){
		iter.se(i+10);
		iter.gf();
	}

	//go back and forward
	iter.se(30);
	cout<<"beg val "<<iter.gtv()<<endl;
	iter.gb();
	cout<<"back "<<iter.gtv()<<endl;
	iter.gf();
	cout<<"forw "<<iter.gtv()<<endl;	
}