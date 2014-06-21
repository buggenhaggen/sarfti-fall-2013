#include <iostream>
using namespace std;

struct list_elem
{
	int val;
	list_elem* next;
};

struct One_Dir_List
{
	list_elem* first;
	list_elem* fol;
	int size;
	int cnt;
};


int next_elem(One_Dir_List &list)
{
	if((list.fol->next) == NULL)
	{
		printf("Last Element is Achived\n");
		return 1;
	}
		
	else
	{
		list.fol = list.fol->next;
		list.cnt++;
		return 0;
	}
}

void first_elem(One_Dir_List &list)
{
	list.fol = list.first;
	list.cnt = 1;
}

int get_elem(One_Dir_List &list)
{
	return list.fol->val;
}


void set_elem(One_Dir_List &list, int val)
{
	list.fol->val = val;
	list.fol->next = list.fol + 1;
}




void insert_elem(list_elem* el_ptr, One_Dir_List &list, int val)
{
	el_ptr->next = list.fol->next;
	list.fol->next = el_ptr;
	el_ptr->val = val;

	list.size++;
	list.cnt++;
}



void main()
{
	list_elem list[1000];
	One_Dir_List list_str;
	
	
	list_str.first = list;
	list_str.fol = list_str.first;

	list_str.cnt = 0;
	list_str.size = 0;


	cout<<"SINGLY LINKER LIST:\n\n";

	//Заполнение списка

	for(int i = 0; i< 10; i++)
	{
		set_elem(list_str,i);
		next_elem(list_str);
		list_str.size++;
	}

	first_elem(list_str);

	//Вывод элементов списка

	cout<<"list elements:\n";

	while(list_str.cnt <= list_str.size)
	{
		cout<<get_elem(list_str)<<" ";
		next_elem(list_str);
	}
	cout<<endl;



	//Нахождение середины

	int sered = list_str.size/2;

	//Переход в начало
	first_elem(list_str);

	//Переход в середину

	for(int i = 0; i<sered; i++)
	{
		next_elem(list_str);
	}

	list_elem b;	//Новый элемент списка


	insert_elem(&b, list_str, 200);	//Вставка в середину


	first_elem(list_str);

	//Вывод элементов списка после вставки

	cout<<"list elements after past:\n";

	while(list_str.cnt <= list_str.size)
	{
		cout<<get_elem(list_str)<<" ";
		next_elem(list_str);
	}
	cout<<endl;

}