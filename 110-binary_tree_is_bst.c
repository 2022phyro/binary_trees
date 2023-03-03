#include "binary_trees.h"
/**
 * b_st - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * @prev: the previous node
 * @x: the direction to reverse whether ascending or descending
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int b_st(binary_tree_t *tree, binary_tree_t *prev, bool x)
{
	if (tree && x == false)
	{
		if (!(b_st(tree->left, prev, x)))
			return (0);
		if ((prev != NULL && prev->n > tree->n) ||
			(dp_count(tree, tree->n) > 1))
			return (0);
		prev = tree;
		return (b_st(tree->right, prev, x));
	}
	if (tree && x == true)
	{
		if (!(b_st(tree->right, prev, x)))
			return (0);
		if ((prev != NULL && prev->n < tree->n) ||
			(dp_count(tree, tree->n) > 1))
			return (0);
		prev = tree;
		return (b_st(tree->left, prev, x));
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
	return ((b_st((binary_tree_t *)tree, NULL, true)) &&
	 (b_st((binary_tree_t *)tree, NULL, false)));
}
/**
 * dp_count - this counts all occurences of a value in the tree
 *
 * @root: the tree
 * @n: the value
 * Return: the total count
 */
int dp_count(bst_t *root, int n)
{
	int r = 0;

	if (root)
	{
		if (root->n == n)
			r++;
		r += dp_count(root->right, n);
		r += dp_count(root->left, n);
		return (r);
	}
	return (0);
}
