#include "binary_trees.h"

/**
 * bst_search - program that searches for a value in a Binary Search Tree (BST)
 *
 * this function traverses the BST in a depth-first manner, following the
 * binary search tree property (left < parent < right) to efficiently
 * locate the desired value;
 * it recursively searches through the left subtree if the value is less than
 * the current node's value, and the right subtree if the value is greater;
 * if a node with the value is found, a pointer to that node is returned;
 * if the value is not found in the tree or the tree is NULL, the function returns NULL
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search for within the BST
 *
 * Return: a pointer to the node containing the value,
 *         or NULL if the value is not found or the tree is NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (tree->left == NULL && tree->right == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}
