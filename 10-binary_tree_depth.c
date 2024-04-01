#include "binary_trees.h"

/**
 * binary_tree_depth - program that measures the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth of
 *
 * Return: the depth of the node, or 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
