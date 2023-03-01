#include "binary_trees.h"
/**
 * binary_tree_balance - This measures the balance factor of a tree
 * @tree: the tree to be measured
 * Return: the balance factor
 */
size_t be(const binary_tree_t *tree)
{
	size_t l, r;

        if (tree)
        {
                l = tree->left ? 1 + be(tree->left) : 0;
                r = tree->right ? 1 + be(tree->right) : 0;
                return (l > r ? l : r);
        }
        return (0);

}
int binary_tree_balance(const binary_tree_t *tree)
{
	int i;
	const binary_tree_t *l, *r;

	i = 0;
	if (tree == NULL)
		return (0);
	l = tree->left;
	r = tree->right;
	printf("%d - %d", be(l), be(r));
	i = be(l) - be(r);
	printf("%d\n", binary_tree_height(tree));
	return (i);
}
