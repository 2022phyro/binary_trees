#include "binary_trees.h"
/**
 * be - This measures the balance factor of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
size_t be(const binary_tree_t *tree)
{
	size_t l = 1, r = 1;

	if (tree)
	{
		if (tree->right)
			r += be(tree->right);
		if (tree->left)
			l += be(tree->left);
		return (l > r ? l : r);
	}
	return (0);
}
/**
 * level_up - moves through the tree in levelorder
 * @tree: the tree being considered
 * @level: the current level
 * @func: the function to be performed on the nodes at each level
 * Return: nothing, it is void
 */
void level_up(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
	{
		func(tree->n);
		return;
	}
	else if (level > 1)
	{
		level_up(tree->left, level - 1, func);
		level_up(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - traverses a tree in level order
 * @tree: the tree to be traversed
 * @func: a function to be performed on each member of the tree
 * Return: nothing, it is void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, j;

	if (tree == NULL || func == NULL)
		return;
	i = be(tree);
	for (j = 1; j <= i + 1; j++)
		level_up(tree, j - 1, func);
}
