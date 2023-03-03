#include "binary_trees.h"
/**
 * ldepth - gives the depth of a left node of a binary tree
 *
 * @tree: the tree being considered
 * Return: the tree's depth
 */
int ldepth(const binary_tree_t *tree)
{
	int d;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}
/**
 * b_p - checks if a tree is perfect
 *
 * @tree: the tree to becheked
 * @d: the left depth
 * @level: the current level
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
	return (b_p(tree->left, d, level + 1) &&
		b_p(tree->right, d, level + 1));
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

	return (b_p(tree, ldepth(tree), 0));

}
