#include "binary_trees.h"

/**
 * binary_tree_rotate_left - program that performs a left-rotation on a binary tree
 *
 * the function performs a left rotation on the binary tree with the specified root node;
 * the right child of the 'tree' becomes the new root of the subtree, and the original root
 * becomes the left child of this new root;
 * if the new root had a left child, it is transferred to become the right child of the original root;
 * the function takes care of updating parent pointers to maintain the binary tree properties;
 * if 'tree' is NULL or doesn't have a right child, the function returns NULL indicating that
 * a left rotation is not possible
 *
 * @tree: a pointer to the root node of the binary tree to rotate
 *
 * Return: a pointer to the new root node of the tree after rotation
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->right;

	tree->right = pivot->left;

	if (pivot->left)
		pivot->left->parent = tree;

	pivot->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;

		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}
