# include <iostream>
# include <conio.h>
using namespace std;

struct node
{
    int info;
    node *l, *r;
};

node * tree=NULL;
void push(int a,node **t)
{
    if ((*t)==NULL)
    {
        (*t)=new node;
        (*t)->info=a; //Кладем в выделенное место аргумент a
        (*t)->l=(*t)->r=NULL;
        return;
    }
        if (a>(*t)->info&&a%2==0) push(a,&(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
        else push(a,&(*t)->l); //Иначе кладем его влево
}

void print (node *t,int u) 
{
    if (t==NULL) return;
    else
    {
    print(t->l,++u);//С помощью рекурсивного посещаем левое поддерево
    for (int i=0;i<u;++i) cout<<"|";
    cout<<t->info<<endl;
    u--;
    }
    print(t->r,++u); //С помощью рекурсии посещаем правое поддерево
}

void main ()
{   
	  setlocale(LC_ALL, "RUSSIAN");
    int n; //Количество элементов
    int s; //Число, передаваемое в дерево
    cout<<"введите количество элементов  ";
    cin>>n;

    for (int i=0;i<n;++i)
    {
    cout<<"ведите число  ";
    cin>>s;
   
    push(s,&tree);
    }
    cout<<"ваше дерево\n";
    print(tree,0);
    getch();       
} 