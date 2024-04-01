#include "binary_trees.h"

/**
 * calculateHeightRecursively - program that recursively calculates the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to calculate the height of
 *
 * Return: the height of the tree, or 0 if the tree is NULL
 */

int calculateHeightRecursively(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;

	if (!tree)
		return (0);

	leftHeight = calculateHeightRecursively(tree->left) + 1;
	rightHeight = calculateHeightRecursively(tree->right) + 1;

	if (leftHeight > rightHeight)
		return (leftHeight);

	else
		return (rightHeight);
}



/**
 * calculateTreeHeight - a wrapper function for 'calculateHeightRecursively',
 * used to initiate the height calculation
 *
 * @tree: a pointer to the root node of the tree to calculate the height of
 *
 * Return: the height of the tree, or 0 if the tree is NULL
 */

int calculateTreeHeight(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (calculateHeightRecursively(tree));
}



/**
 * checkIfAVL - recursive function that checks if a binary tree is an AVL tree
 * (a balanced binary search tree)
 *
 * @tree: a pointer to the root node of the tree to check
 * @minValue: the minimum value node allowed in this subtree, used for BST validation
 * @maxValue: the maximum value node allowed in this subtree, used for BST validation
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */

int checkIfAVL(const binary_tree_t *tree, int minValue, int maxValue)
{
	int leftTreeHeight, rightTreeHeight;

	if (!tree)
		return (1);

	if (tree->n <= minValue || tree->n >= maxValue)
		return (0);

	leftTreeHeight = calculateTreeHeight(tree->left);
	rightTreeHeight = calculateTreeHeight(tree->right);

	if (abs(leftTreeHeight - rightTreeHeight) > 1)
		return (0);

	return (checkIfAVL(tree->left, minValue, tree->n) &&
		checkIfAVL(tree->right, tree->n, maxValue));
}



/**
 * binary_tree_is_avl - program that checks if a binary tree is an AVL tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (checkIfAVL(tree, -1000, 1000));
}
