#include <iostream>
using namespace std;

struct list_elem
{
	int val;
	list_elem* prev;
	list_elem* next;
};

struct Two_Dir_List
{
	list_elem* first;
	list_elem* fol;
	int size;
	int cnt;
};



void set_elem(Two_Dir_List &list, int val)
{
	list.fol->val = val;
	list.fol->next = list.fol + 1;
}


class IterTwoList
{
	list_elem* el;
	Two_Dir_List* list;

	public:

		IterTwoList(Two_Dir_List* list)
		{
			this->list = list;
			this->el = list->first;
		}

		list_elem* get_el_ptr()
		{
			return this->el;
		}

		int get_val()
		{
			return this->list->fol->val;
		}


		void go_forw()
		{
			list->fol = list->fol->next;
			list->cnt++;
		}


		void go_back()
		{
			list->fol = list->fol->prev;
			list->cnt--;
		}


		void set_elem(int val)
		{
			/*el->next = list->fol + 1;
			el->prev = list->fol - 1;
			el = list->fol;
			el->val = val;*/
			list->fol->next = list->fol + 1;
			list->fol->prev = list->fol - 1;
			list->fol->val = val;
		}

		void to_begin()
		{

			list->cnt = 1;
		}
};


void main()
{
	list_elem list[1000];
	Two_Dir_List list_str;
	
	
	list_str.first = list;
	list_str.fol = list_str.first;

	list_str.cnt = 0;
	list_str.size = 0;

	cout<<"DOUBLE LINKER LIST:\n\n";



	IterTwoList iter(&list_str); //Привязывание итератора к списку


	//Заполнение списка

	for(int i = 0; i < 5; i++)
	{
		iter.set_elem(i+10);
		iter.go_forw();
	}


	iter.set_elem(30);

	cout<<"Begin value "<<iter.get_val()<<endl; //Вывод начального значения

	iter.go_back();	//Шаг назад

	cout<<"after go back "<<iter.get_val()<<endl;

	iter.go_forw();	//Шаг вперед

	cout<<"after go forward "<<iter.get_val()<<endl;	

}