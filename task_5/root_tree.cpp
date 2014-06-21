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




int insert(struct tree * search_tree, int item)
{
	struct node * search_node, **new_el;

	if(item%2 == 1)
	{
		//search_tree->root->left = (node*)malloc(sizeof node);
		new_el = &search_tree->root->left;
		search_node = search_tree->root->left;
	}

	else
	{
		//search_tree->root->right = (node*)malloc(sizeof node);
		new_el = &search_tree->root->right;
		search_node = search_tree->root->right;
	}


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




void main()
{
	tree* search_tree;
	search_tree = tree_create();

	cout << "ROOT TREE\n";



	//создание корневого элемента

	search_tree -> root = (node*)malloc(sizeof node);

	search_tree -> root ->data = 0;
	search_tree -> root ->left = NULL;
	search_tree -> root ->right = NULL;

	//добавление элементов в дерево

	int status;

	for(int i = 0; i<30 ;i++)
	{
		status = insert(search_tree,rand()%60);
	}

	cout<<"tree walk\n";
	walk2(search_tree);	//обход дерева

	cout<<endl;
}