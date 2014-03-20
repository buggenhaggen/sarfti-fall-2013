#include "queue.h"
#include <iostream>
using namespace std;
 
void queue::init()
{
    start=0;
    end=0;
}
 
void queue::get()
{
    if ( start==end )
    {
        cout<<"Очередь пуста!";
        return;
    }
	cout<<"Считать элемент  ";
	for(int i=1; i<=500; i++)
	{
    cout<<a[i]<<"	";  
	}
	end++;
}
 
void queue::put( int n )
{
    if ( 501==start )
    {
        cout<<"Очередь полная!";
        return;
    }	
    a[n] = n;
    cout<<a[n]<<"	";	
}
