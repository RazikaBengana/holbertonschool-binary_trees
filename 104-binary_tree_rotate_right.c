#include "binary_trees.h"

/**
 * binary_tree_rotate_right - program that performs a right-rotation on a binary tree
 *
 * a right rotation is a tree transformation that shifts the structure of the tree
 * to the right;
 * it is used in balancing binary search trees, such as AVL trees or Red-Black trees;
 * the operation targets a specific node (the "pivot") and modifies the pointers
 * to rotate the subtree rooted at this node to the right;
 *
 * this function takes a pointer to the root node of the subtree to rotate and
 * performs the rotation, adjusting the necessary parent and child pointers to
 * maintain the binary tree properties;
 * the pivot for the rotation is the left child of the provided subtree root
 *
 * @tree: a pointer to the root node of the subtree to rotate
 *
 * Return: a pointer to the new root of the subtree after rotation;
 *         if the input tree is NULL, the function returns NULL without performing any operation
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->left;

	tree->left = pivot->right;

	if (pivot->right)
		pivot->right->parent = tree;

	pivot->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;

		else
			tree->parent->left = pivot;
	}

	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}
