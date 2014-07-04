#include "List.h"
using namespace std;
int main()
{
	////Настройки шрифтов и региональных стандартов: 
	setlocale(LC_ALL, "Russian");
	//инициализируем рандом
	srand((unsigned)time( NULL )); 
	cout<<"Задайте количество элементов списка: ";
	int count;
	cin>>count;
	MyList initial_list;
	for (int i = 0; i < count; i++)
	{
		//заполняем список значениями от 0 до 100
		initial_list.Add(rand()%100);
	}
	do
	{
		cout<<"Изначальный список: \n";
		cout << initial_list;
		cout<<"Введите число: ";
		int val;
		cin>>val;
		initial_list.AddToListCenter(val);
		cout<<"Измененный список: \n";
		cout << initial_list;
	} while (_getch() != 27);
	return 0;
}
