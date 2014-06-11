#define COLOR_RED 1
#define COLOR_BLACK 0
#include <iostream>
struct rbtree
	{
		int key;
		char *value;
		int color;
		struct rbtree *parent;
		struct rbtree *left;
		struct rbtree *right;
};
	struct rbtree EmptyNode = {0, 0, COLOR_BLACK, NULL, NULL, NULL};
	struct rbtree *NullNode = &EmptyNode;

	
	struct rbtree *rbtree_add(struct rbtree *root, int key, char *value)//добавляем узел
	{
		struct rbtree *node, *parent = NullNode;
		/* поиск листа для нового элемента */
		for (node = root; node != NullNode &&node != NULL; ) 
		{
			parent = node;
			if (key < node->key)
				node = node->left;
			else if (key > node->key)
				node = node->right;
			else
				return root;
		}
		node = (struct rbtree*)malloc(sizeof(*node));
		if (node == NULL)
			return NULL;
		node->key = key;
		node->value = value;
		node->color =COLOR_RED;
		node->parent = parent;
		node->left = NullNode;
		node->right = NullNode;
		if (parent != NullNode) {
			if (key < parent->key)
				parent->left = node;
			else
				parent->right = node;
		} else {root = node;}
		return 
			rbtree_add(root, key, value);
} 

	//левый поворот
	struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node)
	{
		struct rbtree *right = node->right;
		/* создание узла->правая вествь */
		node->right = right->left;
		if (right->left != NullNode) 
			right->left->parent = node;
		/* создание право->родительская ветвь */
		if (right != NullNode) 
			right->parent = node->parent;
		if (node->parent != NullNode) {
			if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;
		} else {
			root = right;
		}
		right->left = node;
		if (node != NullNode) 
			node->parent = right;
		return root;
	}
	//правый поворот
	struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node)
	{
		struct rbtree *left = node->left;
		/* создание узла->левая ветвь */
		node->left = left->right;
		if (left->right != NullNode) 
			left->right->parent = node;
		/* создание левой->родительская ветвь*/
		if (left != NullNode) 
			left->parent = node->parent;
		if (node->parent != NullNode) {
			if (node == node->parent->right)
				node->parent->right = left;
			else
				node->parent->left = left;
		} else {
			root = left;
		}
		left->right = node;
		if (node != NullNode) 
			node->parent = left;
		return root;
}
		//восстановление свойств после добавления
	struct rbtree *rbtree_fixup_add(struct rbtree *root,struct rbtree *node)
	{
		struct rbtree *uncle;
		/* Текущий узел RED */
		while (node != root && node->parent->color == COLOR_RED) 
		{
			if (node->parent == node->parent->parent->left) 
			{
				/* узел в дереве слева родителя */
				uncle = node->parent->parent->right;
				if (uncle->color == COLOR_RED) 
				{
					/* Случай 1 - соскдний-RED */
					node->parent->color = COLOR_BLACK;
					uncle->color = COLOR_BLACK;
					node->parent->parent->color = COLOR_RED;
					node = node->parent->parent;
				} 
				if( uncle->color != COLOR_RED)
				{
					/* Случай 2 & 3 - соседний - BLACK */
					if (node == node->parent->right)
					{
						/*Приведение случая 2 к случаю 3*/
						node = node->parent;
						root = rbtree_left_rotate(root, node);
					}
					/* Случай 3 */
					node->parent->color = COLOR_BLACK;
					node->parent->parent->color = COLOR_RED;
					root = rbtree_right_rotate(root, node->parent->parent);
				}
				}
			else 
			{
					/* узел в правом дереве */
					uncle = node->parent->parent->left;
					if (uncle->color == COLOR_RED)
					{
						/* соседний is RED */
						node->parent->color = COLOR_BLACK;
						uncle->color = COLOR_BLACK;
						node->parent->parent->color = COLOR_RED;
						node = node->parent->parent;
					} 
					if (uncle->color != COLOR_RED){
						/* соседний is BLACK */
						if (node == node->parent->left) 
						{
							node = node->parent;
							root = rbtree_right_rotate(root, node);
						}
						node->parent->color = COLOR_BLACK;
						node->parent->parent->color = COLOR_RED;
						root = rbtree_left_rotate(root, node->parent->parent);
					}
			}
		}
		root->color = COLOR_BLACK;
		return root;
}
	int main (int argc, char **argv)//формируем дерево
	{
		struct rbtree *tree = NULL;
		tree = rbtree_add(tree, 2, "10");
		tree = rbtree_add(tree, 1, "5");
		tree = rbtree_add(tree, 10, "3");
		tree = rbtree_add(tree, 8, "11");
		tree = rbtree_add(tree, 11, "12");
		tree = rbtree_add(tree, 4, "6");
		tree = rbtree_add(tree, 9, "8");
		tree = rbtree_add(tree, 3, "9");
		tree = rbtree_add(tree, 7, "9");
		tree = rbtree_add(tree, 5, "9");
		tree = rbtree_add(tree, 6, "9");
		return 0;
	}