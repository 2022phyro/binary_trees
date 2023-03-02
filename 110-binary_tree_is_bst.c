#include "binary_trees.h"
/**
 * b_st - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int b_st(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if ((tree->left && tree->left->n > tree->n) ||
		(tree->right && tree->right->n < tree->n))
		return (0);
	l = b_st(tree->left);
	r = b_st(tree->right);
	return (l & r);
}
/**
 * sizes - this returns the size of a tree
 * @tree: the tree being considered
 * Return: the tree's size
 */
size_t sizes(const binary_tree_t * tree)
{
	if (tree)
		return (1 + (sizes(tree->left)) + sizes(tree->right));
	return (0);
}
/**
 * tree_to_array - converts a tree to an array
 *
 * @tree: the tree to be convertes
 * @arr: the array in question
 * @siz: the array size
 * Return: nothing it is void
 */
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
/**
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: The tree to be checked
 * Return: 1 if it's a valid tree or 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int a, i, j, *arr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	a = sizes(tree);
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
	return (b_st(tree));
}
