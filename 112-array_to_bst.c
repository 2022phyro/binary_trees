#include "binary_trees.h"
/**
 * array_to_bst - Converts an array to a BST
 *
 * @array: the array to be converted
 * @size: the array size
 * Return: the newly converted BST or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root;

	if (!(array && array[0]))
		return (NULL);
	root = binary_tree_node(NULL, array[0]);
	if (root)
	{
		for (i = 1; i < size; i++)
			bst_insert(&root, array[i]);
		return (root);
	}
	return (NULL);
}
