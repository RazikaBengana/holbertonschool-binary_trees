#include "binary_trees.h"

/**
 * binary_tree_preorder - program that traverses a binary tree using pre-order traversal
 *
 * in pre-order traversal, the nodes are visited in the following order:
 * 1. current node
 * 2. left subtree
 * 3. right subtree
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node;
 *        the value in the node is passed as a parameter to this function
 *
 * Return: nothing (void)
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
