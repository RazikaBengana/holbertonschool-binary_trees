#include "binary_trees.h"

/**
 * binary_tree_leaves - program that counts the leaves in a binary tree
 *
 * a leaf is a node with no children
 *
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: the total number of leaves in the tree, or 0 if the tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t b_leaves = 0;

	if (tree)
	{
		b_leaves += (!tree->left && !tree->right) ? 1 : 0;
		b_leaves += binary_tree_leaves(tree->left);
		b_leaves += binary_tree_leaves(tree->right);
	}
	return (b_leaves);
}
