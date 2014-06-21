#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;


//структура узла дерева
struct node
{
  int data;
  struct node * left;
  struct node * right;
};



//структура дерева
struct tree
{
  struct node * root;	// указатель на корень дерева
  int count;			// количество узлов в дереве
};


//генерация дерева
struct tree * tree_create(void)		//!!!!!!!!!!!!!!!!!!!
{
	struct tree * new_tree = (tree*) malloc(sizeof * new_tree);
	if (new_tree == NULL) return NULL;
	new_tree->root = NULL;
	new_tree->count = 0;
	return new_tree;
}


//поиск наличия элемента с ключом item
int bin_search(const struct tree * search_tree, int item)
{
  const struct node * search_node;
  search_node = search_tree->root;
	for(;;)
	{
		if (search_node == NULL) return 0;
		else if (item == search_node->data) return 1;
		else if (item > search_node->data) search_node = search_node->right;  
		else search_node = search_node->left;  
	}
}


//добавление элементов

int insert(struct tree * search_tree, int item)
{
	struct node * search_node, **new_el;

	new_el = &search_tree->root;
	search_node = search_tree->root;

	for(;;)
	{
		if(search_node == NULL)
		{
			search_node = *new_el = (node*)malloc(sizeof * search_node);
			if(search_node != NULL)
			{
				search_node->data = item;
				search_node->left = search_node->right=NULL;
				search_tree->count++;
				return 1;
			}
			else return 0;
		}
		else if(item == search_node->data) return 2;
	else if(item > search_node->data)
	{
	new_el = &search_node->right;
	search_node = search_node->right;
		}
		else
		{
			new_el = &search_node->left;
			search_node = search_node->left;
		}
	}
}


//функция для распечатки фрагмента дерева - с любого узла
static void walk(const struct node * search_node)
{
	if(search_node == NULL) return;
	walk(search_node->left);
	printf("%d ", search_node->data);
	walk(search_node->right);
}	



//функция для распечатки дерева целиком - с корня
void walk2(const struct tree * my_tree)
{
	walk(my_tree->root);
}


struct node * tree_maximum(struct tree * search_tree)
{
	struct node * search_node;
	search_node = search_tree->root;
	while (search_node->right != NULL)
			search_node = search_node->right;
	return search_node;
}


int del_node(struct tree * search_tree, int ** item)
{
	struct node ** q,*z;
	
	q=&search_tree->root;
	z=search_tree->root;
	//поиск удаляемого элемента
	for(;;)
	{
		if(z == NULL) return 0;
		else if(item == (int **)z->data) break;
		else if(item > (int **)z->data)
		{
			q = &z->right;
			z = z->right;
		}
		else
		{
			q = &z->left;
			z = z->left;
		}
	}		
	
	// непосредственное удаление элемента
	if(z->right == NULL) *q = z->left;
	else
	{
		struct node * y = z->right;
		if(y->left == NULL)
		{
			y->left = z->left;
			*q-y;
		}
		else
		{
			struct node * x=y->left;
			while(x->left != NULL)
			{
				y = x;
				x = y->left;
			}
			y->left = x->right;
			x->left = z->left;
			x->right = z->right;
			*q=x;
		}
	}

	search_tree->count --;
	free(z);
	return 1;
}


void main()
{

	cout << "BINARY SEARCH TREE\n";
	tree* search_tree;
	search_tree = tree_create();

	//добавление элементов в дерево

	int status;

	for(int i = 0; i<30 ;i++)
	{
		status = insert(search_tree,rand()%60);
	}

	cout<<"tree walk\n";
	walk2(search_tree);	//обход дерева

	cout<<endl;

	//поиск по ключу, например найдем число 40

	int rez_search;

	rez_search = bin_search(search_tree,40);

	if(rez_search == 0)	cout<<"number 40 not found\n";
	else cout<<"number 40 is found\n";

	//найдем максимум

	node* max_node = tree_maximum(search_tree);

	cout<<"max value is "<<max_node->data<<endl;

	//удалим узел, например максимальный

	int rez_del;

	rez_del = del_node(search_tree, (int**) max_node->data);

	walk2(search_tree);	//обход дерева c выводом содержимого
}