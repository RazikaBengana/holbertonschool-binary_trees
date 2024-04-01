#include "binary_trees.h"

/**
 * binary_tree_inorder - program that traverses a binary tree using in-order traversal
 *
 * this function applies the passed function 'func' to each node's value during
 * the traversal
 *
 * in in-order traversal, the nodes are visited in the following order:
 * 1. the left subtree
 * 2. the current node
 * 3. the right subtree
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node's value
 *
 * Return: nothing (void)
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
