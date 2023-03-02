#include "binary_trees.h"
/**
 * bst_insert - inserts a node into a binary tree
 *
 * @tree: the tree to beinserted upon
 * @value: the value
 * Return: the new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *mark;

	if ((*tree) == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	temp = *tree;
	while (true)
	{
		while (temp != NULL && value > temp->n)
		{
			mark = temp;
			temp = temp->right;
		}
		if (temp == NULL)
		{
			temp = insert_right(mark, value);
			return (temp);
		}
		while (temp != NULL && value < temp->n)
		{
			mark = temp;
			temp = temp->left;
		}
		if (temp == NULL)
		{
			temp = insert_left(mark, value);
			return (temp);
		}
		if (value > temp->n &&
			(temp->right == NULL || temp->right->n > value))
		{
			mark = insert_right(temp, value);
			return (mark);

		}
		if (value < temp->n &&
			(temp->left == NULL || temp->left->n < value))
		{
			mark = insert_left(temp, value);
			return (mark);
		}
		if (temp->n == value)
			return (NULL);
	}
	return (NULL);
}
