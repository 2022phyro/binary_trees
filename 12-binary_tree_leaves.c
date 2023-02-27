#include "binary_trees.h"
/**
 * binary_tree_leaves - This counts the leaves in a tree
 * @tree: the root node
 * Return: the total count
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t i;

	i  = 0;
	if (tree == NULL)
		return (i);
	if (tree->right == NULL && tree->left == NULL)
		i += 1;
	i += binary_tree_leaves(tree->left);
	i += binary_tree_leaves(tree->right);
	return (i);
}
