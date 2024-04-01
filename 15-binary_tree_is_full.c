#include "binary_trees.h"

/**
 * binary_tree_is_full - program that checks if a binary tree is full
 *
 * a binary tree is full if every node has either 0 or 2 children
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise or if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	return (left && right);
}
