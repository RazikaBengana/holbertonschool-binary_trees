#include "binary_trees.h"

/**
 * binary_tree_nodes - program that counts the nodes with at least one child in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of nodes in
 *
 * Return: the total number of nodes with at least one child in the whole tree
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right, nodes = 0;

	left = nodes;
	right = nodes;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		nodes = left + right + 1;

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	return (nodes + left + right);
}
