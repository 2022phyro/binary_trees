#include "binary_trees.h"
/**
 * binary_tree_postorder - traveses a tree in postorder
 * @tree: the tree to be traversed
 * @func: A function to be executed on each element
 * Return: Nothing it is void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
