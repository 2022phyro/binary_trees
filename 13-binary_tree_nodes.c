#include "binary_trees.h"
/**
 * binary_tree_nodes - This counts the nodes in a tree
 *
 * @tree: the root node
 * Return: the total count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t i;

	i  = 0;
	if (tree == NULL)
		return (i);
	if (tree->right != NULL || tree->left != NULL)
		i += 1;
	i += binary_tree_nodes(tree->left);
	i += binary_tree_nodes(tree->right);
	return (i);
}
