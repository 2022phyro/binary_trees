#include "binary_trees.h"
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
 * @d: the depth
 * @l: the level
 * Return: 1 or 0 depending on success or failure
 *
 */
int b_p(const binary_tree_t * tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{ 
		return (1);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);


	return (b_p(tree->left) && b_p(tree->right));
}
int binary_tree_is_perfect(const binary_tree_t *tree)
{


	if (tree == NULL)
		return (0);

	return (b_p(tree));

}
