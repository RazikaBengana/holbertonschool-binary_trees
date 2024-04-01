#include "binary_trees.h"

/**
 * binary_tree_uncle - program that finds the uncle of a given node in a binary tree
 *
 * the uncle of a node is the sibling of the node's parent;
 * if the node, its parent, or grandparent is NULL,
 * or if an uncle does not exist, returns NULL
 *
 * @node: a pointer to the node to find the uncle for
 *
 * Return: a pointer to the uncle node if found, NULL otherwise
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	uncle = node->parent->parent;

	if (uncle->left != node->parent)
		return (uncle->left);

	return (uncle->right);
}
