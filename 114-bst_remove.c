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
	bst_t *temp, *mark;

	if (root == NULL)
		return (NULL);
	temp = search(root, value);
	mark = find_s(temp); 
	printf("%d->%d\n", temp->n, mark->n);
	if (temp == NULL)
		return (root);
	mark->left = temp->left;
	temp->left->parent = mark;

	free(temp);
	return (root);
}
bst_t *find_s(bst_t *node)
{
	bst_t *temp;
	if (node->right)
	{
		temp = node->right;
		while (temp->left != NULL)
			temp = temp->left;
		return (temp);
	}
	temp = node->parent;
	while (temp && node == temp->right)
	{
		node = temp;
		temp = temp->parent;
	}
	return (temp);
}
bst_t *search(bst_t *tree, int value)
{
	if (value < tree->n)
		return (search(tree->left, value));
	if (value > tree->n)
		return (search(tree->right, value));
	return (tree);
}
