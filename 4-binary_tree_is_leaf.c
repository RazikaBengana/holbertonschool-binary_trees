#include "binary_trees.h"

/**
 * binary_tree_is_leaf - program that checks if a node in a binary tree is a leaf node
 *
 * a leaf node is defined as a node that does not have any children;
 * both its left and right pointers are NULL
 *
 * @node: a pointer to the node to check
 *
 * Return: 1 if the node is a leaf, or 0 if the node is NULL or it's not a leaf
 *         (if it has at least one child)
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}
