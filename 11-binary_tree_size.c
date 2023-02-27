#include "binary_trees.h"
/**
 * binary_tree_size - gives the size of the tree
 * @tree: the tree to be measred
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t r;

	r = 0;
	if (tree == NULL)
		return (r);
	r += 1;
	r += binary_tree_size(tree->right);
	r += binary_tree_size(tree->left);
	return (r);
}
