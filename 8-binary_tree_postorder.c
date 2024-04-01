#include "binary_trees.h"

/**
 * binary_tree_postorder - program that traverses a binary tree using post-order traversal
 *
 * this function applies the specified function 'func' to each node's value during traversal
 *
 * in post-order traversal, the nodes are recursively visited in the following order:
 * 1. left child
 * 2. right child
 * 3. the parent node
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node’s value;
 *        the value of the node is passed as a parameter to this function
 *
 * Return: nothing (void)
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
