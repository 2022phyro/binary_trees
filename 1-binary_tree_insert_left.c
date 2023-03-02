#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node to the left of the binary tree
 *
 * @parent: the parent node
 * @value: the value of the new node
 * Return: a pointer to the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->right = NULL;
	new_node->parent = parent;
	temp = parent->left;
	new_node->left = temp;
	if (temp != NULL)
		temp->parent = new_node;
	parent->left = new_node;
	return (new_node);
}
