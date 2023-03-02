#include "binary_trees.h"
/**
 * binary_tree_sibling - This returns the sibling of a binary tree
 * @node: the node to find it's sibling
 * Return: a pointer to the sibling or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	if (node == node->parent->right)
		return (node->parent->left);
	return (NULL);
}
