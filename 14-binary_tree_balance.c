#include "binary_trees.h"
/**
 * bee - this measures the balance factor of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
size_t bee(const binary_tree_t *tree)
{
	size_t l = 1, r = 1;

	if (tree)
	{
		if (tree->right)
			r += bee(tree->right);
		if (tree->left)
			l += bee(tree->left);
		return (l > r ? l : r);
	}
	return (0);

}
/**
 * binary_tree_balance - THis gives the balance fator of the tree
 *
 * @tree: the tree to be measured
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bee(tree->left) - bee(tree->right));
}
