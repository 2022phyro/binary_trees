#include "binary_trees.h"
bst_t *find_s(bst_t *node);
bst_t *search(bst_t *tree, int value);
/**
 * bst_remove - Removes a node from a binary tree
 *
 * @root: the tree in question
 * @value: the valu being sought after
 * Return: a pointer to the new head or NULLif it fails
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *mark;/*, *prev;*/

	if (root == NULL)
		return (NULL);
	temp = search(root, value);
	mark = temp->parent;
	printf("%d->%d\n", temp->n, mark->n);
/*	prev = temp->parent;*/
	if (temp == NULL)
		return (NULL);
/*	if (mark == NULL)
	{
		if (prev->left == temp)
			prev->left = NULL;
		else
			prev->right = NULL;
	}
	else if (mark == prev)
	{
		if (prev)
			prev->left = temp->left;
		temp->left->parent = prev;
	
	}
	else if (mark == temp->right)
	{
		if (prev)
			prev->left = mark;
		mark->left = temp->left;
		mark->parent = prev;
	}
	else
	{
		if (mark->left == NULL && mark->right == NULL)
		{
			if (mark == mark->parent->left)
				mark->parent->left = NULL;
			else
				mark->parent->right = NULL;
			
		}
		mark->left->left = temp->left;
		mark->right = temp->right;
		mark->parent = prev;
		if (prev)
			prev->right = temp;
		else
			root = mark;
	}
	free(temp);*/
	return (root);
}
bst_t *find_s(bst_t *node)
{
	if (node->right)
	{
		if (node->right->left == NULL)
			return (node->right);
		else if (node->right->left)
		{
			node = node->right;
			while (node->left != NULL)
				node = node->left;
			return (node);
		}
	}
	if (node->parent && node->parent->n > node->n)
		return (node->parent);
	return (NULL);
}
bst_t *search(bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value < tree->n)
		return (search(tree->left, value));
	if (value > tree->n)
		return (search(tree->right, value));
	return (tree);
}
