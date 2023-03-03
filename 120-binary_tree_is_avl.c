#include "binary_trees.h"
int dp_count(bst_t *root, int n);
/**
 * av_l - Checks if a binary tree is an AVL tree
 * @tree: The tree to be checked
 * @prev: the previous node
 * @x: the diection to traverse wheter ascending or descending
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int av_l(binary_tree_t *tree, binary_tree_t *prev, bool x)
{
	int l;

	if (tree && x == false)
	{
		if (!(av_l(tree->left, prev, x)))
			return (0);
		if ((prev != NULL && prev->n > tree->n) ||
			(dp_count(tree, tree->n) > 1))
			return (0);
		l = bee(tree->left) - bee(tree->right);
		if (!(l >= -1 && l <= 1))
			return (0);
		prev = tree;
		return (av_l(tree->right, prev, x));
	}
	if (tree && x == true)
	{
		if (!(av_l(tree->right, prev, x)))
			return (0);
		if ((prev != NULL && prev->n > tree->n) ||
			(dp_count(tree, tree->n) > 1))
			return (0);
		l = bee(tree->left) - bee(tree->right);
		if (!(l >= -1 && l <= 1))
			return (0);
		prev = tree;
		return (av_l(tree->left, prev, x));
	}
	return (1);
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return ((av_l((binary_tree_t *)tree, NULL, true)) &&
		(av_l((binary_tree_t *)tree, NULL, false)));
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
/**
 * bee - this measures the height of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
size_t bee(binary_tree_t *tree)
{
	size_t l = 1, r = 1;

	if (tree)
	{
		if (tree->right)
			r += bee(tree->right);
		if (tree->left)
			l += bee(tree->left);
		return (l > r ? l : r);
	}
	return (0);

}
