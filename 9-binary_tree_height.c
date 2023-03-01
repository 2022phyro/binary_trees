#include "binary_trees.h"
/**
 * binary_tree_height - Returns the height of a tree
 * @tree: the root
 * Return: the height or zero if the node is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return (l > r ? l : r);
	}
	return (0);
}
