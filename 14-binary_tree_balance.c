#include "binary_trees.h"

/**
 * binary_tree_height - program that calculates the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if the tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left1, right1;

		left1 = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right1 = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left1 > right1) ? left1 : right1);
	}
	return (0);
}



/**
 * binary_tree_balance - program that measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of the tree --> it is the difference in heights between the left and right subtrees;
 *         if the tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
