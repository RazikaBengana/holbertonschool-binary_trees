#include "binary_trees.h"

/**
 * binary_trees_ancestor - program that finds the lowest common ancestor of two nodes in a binary tree
 *
 * the lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in the tree
 * that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself)
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two nodes;
 *         if no common ancestor is found or either node is NULL, returns NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp1, *tmp2;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first->parent == second->parent)
		return (first->parent);

	tmp1 = (binary_tree_t *)first;

	while (tmp1)
	{
		tmp2 = (binary_tree_t *)second;

		while (tmp2)
		{
			if (tmp1 == tmp2)
				return (tmp1);

			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
