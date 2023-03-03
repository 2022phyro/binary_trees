#include "binary_trees.h"
/**
 * count - returns the number of nodes in the tree
 *
 * @tree: The tree in question
 * Return: the number of nodes
 */
int count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count(tree->left) + count(tree->right));
}
/**
 * b_cmle - Checks if a tree is a complete one
 *
 * @tree: the treee being checked
 * @i: the index
 * @len: the tree size
 * Return: 1 or 0 depending whether it is a complete tree
 */
int b_cmle(const binary_tree_t *tree, int i, int len)
{
	int k;

	if (tree == NULL)
		return (1);
	if (i >= len)
		return (0);
	k = b_cmle(tree->left, (2 * i) + 1, len) &&
		b_cmle(tree->right, (2 * i) + 2, len);
	return (k);
}
/**
 * binary_tree_is_complete - Checks if a tree is complete using b_cmle
 * @tree: The tree being checked
 * Return: 1 or 0 depending whether the tree is complete 
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int len;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	len = count(tree);
	return (b_cmle(tree, 0, len));
}
