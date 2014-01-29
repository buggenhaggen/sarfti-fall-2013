#include <stdio.h>
#include <iostream>
using namespace std;
//функция для вычисления количества воды скопившейся между стен
int calculate(int *massiv, int size) 
{
	int i, water = 0, result = 0, last_wall = 0;
	int current_height = massiv[0];
	//проходим в прямом направлении
	for (i = 1; i < size; i++) 
	{
		if (massiv[i] >= current_height) 
		{
			result += water;
			water = 0;
			current_height = massiv[i];
			last_wall = i;
		} 
		else 
		{
			water += current_height - massiv[i];            
		}
	}
	//проходим в обратном направлении
	current_height = massiv[size - 1];
	water = 0;
	for (i = size - 2; i >= last_wall; i--) 
	{
		if (massiv[i] >= current_height) 
		{
			result += water;
			water = 0;
			current_height = massiv[i];
		}
		else 
		{
			water += current_height - massiv[i];            
		}
	}
	result += water;
	return result;
}
int main()
{
	setlocale(LC_ALL, "Russian");//поддержка русского языка
	int size;
	cout<<"Введите количество стен: ";
	cin>>size;
	int *massiv = new int[size];//тестовые данные {2,1,6,3,1,2,5,4,5} = 11
	cout<<"Задайте высоту стен:"<<endl;
	for (int i = 0 ; i < size; i++)
	{
		cout<<i+1<<": ";
		cin>>massiv[i];
	}
	cout<<"Количество воды скопившейся между стен = "<<calculate(massiv,size)<<endl;
	delete []massiv;
	return 0;
}
