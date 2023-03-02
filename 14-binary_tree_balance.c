#include "binary_trees.h"
/**
 * binary_tree_balance - This measures the balance factor of a tree
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
		return (l > r ? l: r);

	}
        return (0);

}
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (be(tree->left) - be(tree->right));
}
