#include "binary_trees.h"
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : (-(x)))

/**
 * is_avl - checks if a binary tree is AVL or not
 * @tree: the current root
 * @min: minimum val
 * @max: maximum val
 * @height: the height of the tree
 * Return: 0 or 1
 */
int is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int height_L = 0, height_R = 0;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!is_avl(tree->left, min, tree->n, &height_L) ||
			!is_avl(tree->right, tree->n, max, &height_R))
		return (0);
	*height = MAX(height_L, height_R) + 1;
	return (ABS(height_L - height_R) <= 1);
}
/**
 * binary_tree_is_avl - function that checks if a binary tree is valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int H;

	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX, &H));
}
