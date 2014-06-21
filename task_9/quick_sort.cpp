#include <iostream>
using namespace std;

//алгоритм быстрой сортировки
void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];
 
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (i < j) swap(s_arr[i], s_arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first,j);
}

void main()
{
	int mas[20];


	cout<<"QUICK SORT:\n\n";
	cout<<"source massive:\n";

	for(int i = 0; i<20; i++)
	{
		mas[i] = rand()%205;	//случайно сгенерированный массив
		cout<<mas[i]<<" ";
	}

	cout<<endl;

	qs(mas,0,19);	//функция сортировки слиянием

	cout<<"sorted massive:\n";

	for(int i = 0; i<20 ;i++)
	{
		cout<<mas[i]<<" ";	//вывод отсортированного массива
	}

	cout<<endl;

}