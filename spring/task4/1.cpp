#include "List.h"
int main()
{
	////Настройки шрифтов и региональных стандартов:
	setlocale(LC_ALL, "Russian");
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	do 
	{
		cout<<"Задайте количество элементов списка: ";
		int count;
		cin>>count;
		MyList initial_list;
		for (int i = 0; i < count; i++)
		{
			//заполняем список значениями от 0 до 100
			initial_list.Add(rand()%100);
		}
		cout<<"Изначальный список: \n";
		ListIterator p = initial_list.Begin();
		int i = 0;
		while (i < initial_list.GetCount())
		{
			cout<<*p<<" ";
			p++;
			i++;
		}
		p = initial_list.LastItem();
		i = 0;
		cout<<endl<<"Список в обратном порядке: \n";
		while (i < initial_list.GetCount())
		{
			cout<<*p<<" ";
			p--;
			i++;
		}
		cout<<endl;
	} while (_getch() != 27);
	
	return 0;
}
