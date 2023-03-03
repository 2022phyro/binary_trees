#include "binary_trees.h"
/**
 * b_st - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int b_st(binary_tree_t *tree, binary_tree_t *prev)
{
	if (tree)
	{
		if (!(b_st(tree->left, prev)))
			return (0);
		if (prev != NULL && prev->n > tree->n)
			return (0);
		prev = tree;
		return b_st(tree->right, prev);
	}
	return (1);
}
/**
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (b_st((binary_tree_t *)tree, NULL));
}
