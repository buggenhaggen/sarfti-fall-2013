#pragma once
#include <iostream>
#include <string>
 
using namespace std;
 
struct node // структура для представления узлов дерева
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; height = 1; }
};
 
class Tree
{
public:
    Tree();
    ~Tree();
    void Add(const int &key);
 
private:
    node *Head;
};