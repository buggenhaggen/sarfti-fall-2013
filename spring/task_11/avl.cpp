#include "AVL.h"
#include <iostream>
#include <string>
 
using namespace std;
 
unsigned char height(node* p) // обертка для поля height
{
    return p?p->height:0;
}
 
int bfactor(node* p) // вычисляет balance factor заданного узла
{
    return height(p->right)-height(p->left);
}
 
void fixheight(node* p) // восстанавливает корректное значение поля height заданного узла
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}
 
node* rotateright(node* p) // правый поворот вокруг p
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}
 
node* rotateleft(node* q) // левый поворот вокруг q
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}
 
node* balance(node* p) // балансировка узла p
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}
 
node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new node(k);
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}
 
Tree::Tree()
{
    Head = NULL;
}
 
Tree::~Tree()
{
 
}
 
void Tree::Add(const int &key)
{
    insert(Head, key);
}
 

void main()
{
    Tree tree;
    tree.Add(2);
    tree.Add(1);
    tree.Add(10);
    tree.Add(8);
    tree.Add(11);
    tree.Add(4);
    tree.Add(9);
    tree.Add(3);
	 tree.Add(7);
    tree.Add(5);
    tree.Add(6);
    return;
}