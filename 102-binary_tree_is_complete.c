#include "binary_trees.h"
int count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count(tree->left) + count(tree->right));
}
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
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int len;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	len = count(tree);
	return b_cmle(tree, 0, len);
}
