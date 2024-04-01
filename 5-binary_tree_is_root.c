#include "binary_trees.h"

/**
 * binary_tree_is_root - program that checks if a given node is the root of a binary tree
 *
 * a node is considered the root if it has no parent
 *
 * @node: a pointer to the node to check
 *
 * Return: 1 if the node is the root, 0 otherwise or if the node is NULL
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
