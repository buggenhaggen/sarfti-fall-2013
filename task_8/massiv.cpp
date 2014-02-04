#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;
int main(void)
{
        const int size=9;
        const int size1=5;
        const int size2=4;
        int a[size]={2, 5, 1, 2, 3, 4, 7, 7, 6};
		int a1[size1]={2, 5, 1, 2, 3};
		int a2[size2]={4, 7, 7, 6};
        int max1=0;//массив1
        int i_1=0;
        for(int i=0; i<size1; i++)
        {
			if(a1[i]>max1){max1=a1[i];i_1=i;}
		}
        int max2=0;//массив2
        int i_2=0;
        for(int i=0; i<size2; i++)
        {
			if(a2[i]>max2){max2=a2[i];i_1=i;}
        }
        
        int max=0, i=0;//исходный
        for(int j=1; j<=size; j++)
        {
             if(a[j]>max){ max=a[j];i=j;}
        }
        int k, r, r_max, k_max;
        if(max1>max2){r=max2;k=max1;r_max=i_2;k_max=i;}
        else{r=max1;k=max2;r_max=i_1;k_max=i;}
        int v=0;
        for(int i=r_max; i<k_max; i++){v+=(r-a[i]);}
        cout<<"V = "<<v<<endl;
        getch ();
}