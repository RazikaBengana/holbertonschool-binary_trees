#include "binary_trees.h"

/**
 * is_valid_BST_helper - helper function to check if a binary tree is a BST
 *
 * this function recursively traverses the tree in in-order fashion and checks if
 * the value of the current node is greater than the value of the previous node,
 * as it should be in a valid BST
 *
 * @tree: a pointer to the root node of the binary tree to check
 * @prev: a pointer to an integer that stores the value of the previously visited node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int is_valid_BST_helper(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!is_valid_BST_helper(tree->left, prev))
			return (0);

		if (tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return (is_valid_BST_helper(tree->right, prev));
	}

	return (1);
}



/**
 * binary_tree_is_bst - program that checks if a binary tree is a valid Binary Search Tree (BST)
 *
 * a binary tree is a BST if the nodes follow the BST property:
 * - the value of every node in a node's left subtree is less than the node's value
 * - the value of every node in a node's right subtree is greater than the node's value
 *
 * @tree: a pointer to the root node of the binary tree to be checked
 *
 * Return: 1 if the binary tree is a valid BST, and 0 if it's not or if the tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	return (is_valid_BST_helper(tree, &prev));
}
