#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int how_water(int *mass,int sz) //ф-я расчета кол-ва воды в щелях
{
	int l_wall=0,r_wall=0,l=0,water=0;
	--sz;
	while(l<sz) // пока размер массива больше чем 
	{
		if(mass[sz]>r_wall) r_wall=mass[sz]; // если последняя стена больше чем самая большая найденная, то она самая большая
		if(mass[l]>l_wall) l_wall=mass[l]; // если текущая стена больше чем левая то леваой присваем высоту текущей стены
		if(l_wall>=r_wall) water+=r_wall-mass[sz--]; // если левая стена больше или равна самой большой найденной справа то прибавляем воду
		else water+=l_wall-mass[l++]; // иначе просто льем воды
	}
	return water;
}

int main()
{
	int sz,i;
	cout<<"Input massiv size: ";
	cin>>sz;
	int *mass=new int[sz];
	cout<<"Input wall size:\n";
	for(i=0;i<sz;++i)
	{
		cout<<i+1<<": ";
		cin>>mass[i];
	}
	cout<<"Water: "<<how_water(mass,sz)<<endl;
	return 0;
}