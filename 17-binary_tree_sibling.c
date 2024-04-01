#include "binary_trees.h"

/**
 * binary_tree_sibling - program that finds the sibling of a given node in a binary tree
 *
 * @node: the node to find the sibling of
 *
 * Return: the sibling node if found, NULL otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *root;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	root = node->parent;

	if (root->left != node)
		return (root->left);

	return (root->right);
}
