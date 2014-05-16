#include "d_list.h"
#include "conio.h"
typedef int tip;
D_List<tip> the_list;      // создается пустой список
int main()
{ setlocale(LC_ALL, "RUSSIAN");
	int ret  = 0;
  D_List<tip>::iterator list_iter;
    
  for (int j = 0; j < 5; ++j)// занесение значений в список
    the_list.add_front(j);
   
    
  cout<<"вывод списка с помощью итератора в прямом порядке"<<"\n";
  for ( list_iter = the_list.front( ) ;// вывод значения содержимого спискаиспользуя итератор
        list_iter != the_list.rear( ) ;
        ++list_iter )
    cout << *list_iter << " ";
  cout << endl;
    cout<<"вывод списка с помощью итератора в обратном порядке"<<"\n";
  for ( list_iter = the_list.rear( ) ; list_iter != the_list.front( ) ; )// вывод содержимого списка в обратном порядке
  {   --list_iter; 
       cout << *list_iter << " ";
  }
  cout << endl;
  the_list.remove_it(the_list.find(3));//удаление третьего элемента из списка
  cout<<"вывод списка, удалив третий элмент"<<"\n";
  the_list.print( );//печать списка
  getch();
  return 0;
}