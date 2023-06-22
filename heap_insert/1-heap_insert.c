#include "binary_trees.h"
/**
 * size_tree - the size of the binary tree
 * @tree: tree
 * Return: size
 **/
size_t size_tree(const binary_tree_t *tree)
{
	size_t bt_size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		bt_size = bt_size + size_tree(tree->left);
	if (tree->right != NULL)
		bt_size = bt_size + size_tree(tree->right);
	bt_size = bt_size + 1;
	return (bt_size);
}
/**
 * check_father- check fadher
 * @father: pointer
 * @son: pointer
 * Return: void
 */
void check_father(heap_t **son, heap_t **father)
{
	heap_t *c_left, *c_right, *child = *son, *parent = *father;

	c_right = (*son)->right, c_left = (*son)->left;
	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*father = child;
		}
		child->parent = parent->parent;
		parent->parent = child;
		parent->left = c_left;
		parent->right = c_right;
	}
}
/**
 * perfect_binary_tree - checks if the binary tree is perfect
 * @tree: a tree
 * Return: 1 or 0
 */
int perfect_binary_tree(const binary_tree_t *tree)
{
	int left_size, right_size;

	if (tree == NULL)
		return (0);
	left_size = size_tree(tree->left);
	right_size = size_tree(tree->right);
	if (left_size == right_size)
		return (1);
	return (0);
}
/**
 * heap_insert- a function that inserts a value into a Max Binary Heap
 * @root: pointer
 * @value: the value
 * Return: 1 or 0
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (perfect_binary_tree(*root) || (!perfect_binary_tree((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			newNode = heap_insert(&((*root))->left, value);
			check_father(&((*root)->left), root);
			return (newNode);
		}
		else
		{
			newNode = binary_tree_node(*root, value);
			(*root)->left = newNode;
			check_father(&((*root)->left), root);
			return (newNode);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			newNode = heap_insert(&((*root)->right), value);
			check_father(&((*root)->right), root);
			return (newNode);
		}
		else
		{
			newNode = binary_tree_node(*root, value);
			(*root)->right = newNode;
			check_father(&((*root)->right), root);
			return (newNode);
		}
	}
	return (NULL);
}
