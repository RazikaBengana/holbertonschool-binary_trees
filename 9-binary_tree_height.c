#include "binary_trees.h"

/**
 * binary_tree_height - program that calculates the height of a binary tree
 *
 * the height is the number of edges on the longest path from the root node to a leaf node;
 * if the tree is empty (NULL), or if it only has a root node without any children,
 * the height is considered to be 0
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if the tree is NULL or has no children
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Lheight, Rheight;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	Lheight = binary_tree_height(tree->left);
	Rheight = binary_tree_height(tree->right);

	if (Lheight >= Rheight)
		return (Lheight + 1);

	return (Rheight + 1);
}
