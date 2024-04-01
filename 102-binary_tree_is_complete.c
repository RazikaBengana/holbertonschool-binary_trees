#include "binary_trees.h"

/**
 * binary_tree_size - program that calculates the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: the size of the tree, or 0 if the tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	/* Recursively count the size of each subtree and add them together */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}



/**
 * is_tree_complete - program that checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check for completeness
 * @i: the index of the current node in an array representation of the tree
 * @size: the total size of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int is_tree_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	/* If this node is beyond the size of the tree, then it's not complete */
	if (i >= size)
		return (0);

	/* Recursively check the left and right subtrees */
	return (is_tree_complete(tree->left, (2 * i) + 1, size) &&
		is_tree_complete(tree->right, (2 * i) + 2, size));
}



/**
 * binary_tree_is_complete - program that determines if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 if it is incomplete or the tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Use the helper function 'is_tree_complete' to check tree completeness */
	return (is_tree_complete(tree, 0, binary_tree_size(tree)));
}
