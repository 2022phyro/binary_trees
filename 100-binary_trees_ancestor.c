#include "binary_trees.h"
/**
 * deth - finds the depth of a tree
 * @tree: the tree to be measured
 * Return: the tree's depth
 */
size_t deth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (1 + deth(tree->parent));
}
/**
 * binary_trees_ancestor - This finds the lowest common ancestor
 *
 * @first: the first node
 * @second: the second node
 * Return: a pointer to the l.c.a or null if none was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	if (deth(first) < deth(second))
	{
		while (deth(second) > deth(first))
		{
			second = second->parent;
			if (second == first)
				return ((binary_tree_t *)first);
		}
	}
	else if (deth(second) < deth(first))
	{
		while (deth(first) > deth(second))
		{
			first = first->parent;
			if (first == second)
				return ((binary_tree_t *)first);
		}
	}
	if (first == second)
		return ((binary_tree_t *)first);
	while (first != NULL)
	{
		first = first->parent;
		second = second->parent;
		if (first == second)
			return ((binary_tree_t *)first);

	}
	return (NULL);
}
