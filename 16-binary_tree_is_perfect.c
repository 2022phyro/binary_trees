#include "binary_trees.h"
/**
 * depth - gives the depth of a binary tree
 *
 * @tree: the tree being considered
 * Return: the tree's depth
 */
int depth(const binary_tree_t *tree)
{
	if (tree->parent == NULL)
		return (0);
	return (1 + depth(tree->parent));
}
/**
 * b_p - checks if a tree is perfect
 *
 * @tree: the tree to becheked
 * Return: 1 or 0 depending on success or failure
 *
 */
int b_p(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (b_p(tree->left, d, level + 1) && b_p(tree->right, d, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: the tree being considered
 * Return: the 1 or 0 depending on success or failure
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{


	if (tree == NULL)
		return (0);

	return (b_p(tree, depth(tree), 0));

}
