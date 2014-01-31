#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int wall_water(int *massiv,int k) 
{
int left_wallM=0;
int right_wallM=0;
int l=0;
int water=0;
--k;
while(l<k)  
{
if(massiv[k]>right_wallM) 
{
	right_wallM=massiv[k];
}
if(massiv[l]>left_wallM)
{
	left_wallM=massiv[l];
}
if(left_wallM>=right_wallM) 
{
	water+=right_wallM-massiv[k];
	k--;
}
else {
	water+=left_wallM-massiv[l];
		l++; 
}
}
return water;
}

int main()
{
int k,i;
cout<<"Input massiv size: ";
cin>>k;
int *massiv=new int[k];
cout<<"Input wall size:\n";
for(i=0;i<k;++i)
{
cout<<i+1<<": ";
cin>>massiv[i];
}
cout<<"Water: "<<wall_water(massiv,k)<<endl;
return 0;
}