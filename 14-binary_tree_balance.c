#include "binary_trees.h"
/**
 * b_h - Returns the height of a tree
 * @tree: the root
 * Return: the height or zero if the node is null
 */
size_t b_h(const binary_tree_t *tree)
{
	size_t l, r;

	l = tree->left ? 1 + b_h(tree->left) : 0;
	r = tree->right ? 1 + b_h(tree->right) : 0;
	return (l > r ? l : r);
}
/**
 * binary_tree_balance - This measures the balance factor of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t  **p;

/*	l = malloc(sizeof(binary_tree_t));*/
	p = &tree;
	return b_h(*p);
}
