#include "binary_trees.h"
/**
 * binary_tree_rotate_right - This rotates a binary tree to the right
 * @tree: the tree to be rotated
 * Return: a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	temp = tree->left;
	tree->left = temp->right;
	if (temp->right)
		temp->right->parent = tree;
	temp->parent = tree->parent;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = temp;
		if (tree->parent->right == tree)
			tree->parent->right = temp;
	}
	tree->parent = temp;
	temp->right = tree;
	return (temp);
}
