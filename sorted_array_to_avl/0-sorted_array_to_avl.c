#include "binary_trees.h"

/**
 * node_create - a function that create a node
 * @n: value of the node
 * @parent: the parent node
 * Return: node
 */
avl_t *node_create(int n, avl_t *parent)
{
	avl_t *node = malloc(sizeof(*node));

	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * recursive - a recursive function
 * @parent: the parent node
 * @array: an array of values
 * @first: the begining of the array
 * @array_size: array size
 * Return: NULL
 */
avl_t *recursive(avl_t *parent, int *array, int first, int array_size)
{
	avl_t *new_node;
	int i;

	if (first > array_size)
		return (NULL);
	i = (first + array_size) / 2;
	new_node = node_create(array[i], parent);
	if (!new_node)
		return (NULL);
	new_node->left = recursive(new_node, array, first, i - 1);
	new_node->right = recursive(new_node, array, i + 1, array_size);
	return (new_node);
}

/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array: pointer to first element of array to be converted
 * @size: size of the array
 * Return: NULL or root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (recursive(NULL, array, 0, size - 1));
}