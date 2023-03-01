#include "binary_trees.h"
/**
 * binary_tree_balance - This measures the balance factor of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r;

	l = tree->left ? 1 +  binary_tree_balance(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
	return (l - r);
}
