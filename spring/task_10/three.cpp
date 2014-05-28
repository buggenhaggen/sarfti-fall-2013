#include<iostream>
#include <conio.h>
using namespace std;
 
template <class T,class I> class node
{
      private:
              T x; //ключ
              I info;//информация
              node* LL; //left link
              node* RL; //right link
      public:
             node(){x=0;LL=0;RL=0;};
             ~node()
             {
                  if (LL) LL->~node();
                  if (RL) RL->~node();
                  if (LL) {delete LL; LL=0;}
                  if (RL) {delete RL; RL=0;}
             }
             void putx(T new_x,I new_info){this -> x=new_x;this -> info=new_info;}
             void null_leftlink(){this -> LL=0;}
             void null_rightlink(){this -> RL=0;}
             void add(T new_x, I new_info)
             {
                  if (LL&&(new_x < x)) LL->add(new_x,new_info);
                  if (RL&&(new_x > x)) RL->add(new_x,new_info);
                  
                  if (!LL&&(new_x < x))
                  {
                          node* N=new node;
                          N->x=new_x;
                          N->info=new_info;
                          N->LL=0;
                          N->RL=0;
                          LL=N;
                  }
                  if (!RL&&(new_x > x))
                  {
                          node* N=new node;
                          N->x=new_x;
                          N->info=new_info;
                          N->LL=0;
                          N->RL=0;
                          RL=N;
                  }
             }
             void print(int tab)
             {
                  if (RL) RL-> print(tab + 1);
                     for(int i=1;i!=tab;i++)cout << "  "; cout <<this->x << "-"<< this->info << endl;
                  if(LL) LL->print(tab + 1);      
             }
			 void TreeMax(T getx)
    {
		
        while((x->RL) != NULL)
            x = x->RL;
        cout << "Max element = " <<x;
    }
             void del_all()
             {
                  if (LL) LL->del_all();
                  if (RL) RL->del_all();
                  if (LL) {delete LL; LL=0;}
                  if (RL) {delete RL; RL=0;}
             }
             I get(T getx)
             {
				 for(int i=0;i<=5;i++){
                  if (getx==x) return info;
                  if (LL&&(getx < x)) return LL->get(getx);
				  if (RL&&(getx > x)) return RL->get(getx);}
             }
			
};
 
template <class T,class I> class tree
{
      private:
              node <T,I>* link;
      public:
             tree(){link=0;};
             ~tree(){if (link)link->~node<T,I>();delete link; link=0;};
             void add(T new_x,I new_info)
             {
                  if (link) link->add(new_x,new_info);
                  else
                  {
                      node<T,I>* N=new node<T,I>;
                      N->putx(new_x,new_info);
                      N->null_leftlink();
                      N->null_rightlink();
                      link=N;
                  }
             };
             void print(){if(link)link->print(1);else cout << "No tree existing\n";}
             void del_all(){if(link) link->del_all(); delete link; link=0;}
             I get(T x){if (link) return link->get(x);else cout << "No elements existing\n";}
};
 
int main()
{
    tree <int,char> *T=new tree <int,char>; // создание дерева
    int key; //ключ.
    char val; //значение
	for(int i=0; i<=5; i++){
    cout << "enter key: "; cin >> key;
    cout << "enter int value: "; cin >> val; 
                         T->add(key,val);
	}
	T->print(); 
cout << "what is key of element? "; 
key=0;
 cin >> key;
 cout << "there it is: " << T->get(key) << endl;
 T->del_all();
 

        delete T; //удаление дерева, используется деструктор.
		getch();
}