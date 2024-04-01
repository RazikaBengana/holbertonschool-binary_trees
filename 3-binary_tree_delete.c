#include "binary_trees.h"

/**
 * binary_tree_delete - program that deletes an entire binary tree
 *
 * this function takes a binary tree and deletes all of its nodes,
 * starting from the leaves up to the root;
 * it uses a post-order traversal (left, right, root) to ensure that
 * each node is deleted only after its children have been deleted;
 * this prevents any dangling pointers or memory leaks;
 * if the tree pointer is NULL, the function does nothing
 *
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: nothing (void)
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
