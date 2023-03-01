#include "binary_trees.h"
/**
 * b_f - Checks if a binary tree is full
 * @tree: the tree to be checked
 * Return: 0 or 1 depending on outcome
 */
int b_f(const binary_tree_t *tree)
{
	int final, l, r;

	final = 0;
	if (tree == NULL)
		return (1);
	if ((tree->left != NULL && tree->right != NULL) ||
			(tree->left == NULL && tree->right == NULL))
		final = 1;
	else
		return (0);
	l = b_f(tree->left);
	r = b_f(tree->right);
	if (l == 0 || r == 0)
		return (0);
	return (final);
}
/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: the tree to be checked
 * Return: 0 or 1 depending on outcome
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == 0)
		return (0);
	return (b_f(tree));
}
