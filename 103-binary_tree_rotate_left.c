#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Performs left rotationon a tree
 * @tree: the tree to perform the rotation on
 * Return: a pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL || tree->right == NULL)
		return (tree);
	temp = tree->right;
	tree->right = temp->left;
	if (temp->left)
		temp->left->parent = tree;
	temp->parent = tree->parent;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = temp;
		if (tree->parent->right == tree)
			tree->parent->right = temp;
	}
	tree->parent = temp;
	temp->left = tree;
	return (temp);
}
