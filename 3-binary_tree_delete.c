#include "binary_trees.h"
/**
 * binary_tree_delete - deletes a binary tree
 * @tree: the root node of the tree to delete
 * Return: Nothing: it is void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
