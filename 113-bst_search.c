#include "binary_trees.h"
/**
 * bst_search - Searches through a binary_tree
 *
 * @tree: the tree in question
 * @value: the valu being sought after
 * Return: a pointet to the node or NULLif it fails
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (tree == NULL)
		return (NULL);
	temp = (bst_t *)tree;
	while (true)
	{
		while (temp && value > temp->n)
		{
			temp = temp->right;
		}
		if (temp == NULL)
			return (NULL);
		while (temp && temp->n > value)
		{
			temp = temp->left;
		}
		if (temp == NULL)
			return (NULL);
		if (value == temp->n)
			return (temp);
	}
	return (NULL);
}
