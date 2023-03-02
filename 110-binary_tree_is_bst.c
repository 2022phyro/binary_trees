#include "binary_trees.h"
/**
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int bst(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if ((tree->left && tree->left->n > tree->n) ||
		(tree->right && tree->right->n < tree->n))
		return (0);
	l = bst(tree->left);
	r = bst(tree->right);
	return (l & r);
}
size_t size(const binary_tree_t * tree)
{
	if (tree)
		return (1 + (size(tree->left)) + size(tree->right));
	return (0);
}
void tree_to_array(const binary_tree_t *tree, int *arr, int siz)
{
	binary_tree_t *queue[siz], *node;
	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		node = queue[front++];
		arr[front - 1] = node->n;
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
}
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int a, i, j, *arr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	a = size(tree);
	arr = malloc(sizeof(int) * a);
	tree_to_array(tree, arr, a);
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (arr[j] == arr[i] && j != i)
				return (0);
		}
	}
	free(arr);
	return (bst(tree));
}