#include "binary_trees.h"

/**
 * bst_find_minimum - program that finds the minimum value node in a Binary Search Tree (BST)
 *
 * this function starts at a given node and traverses down the left child,
 * because in a BST, the left child contains smaller values
 *
 * @tree: a pointer to the root node of the BST to search for the minimum value
 *
 * Return: a pointer to the node containing the minimum value, or NULL if the tree is empty
 */

bst_t *bst_find_minimum(bst_t *tree)
{
	bst_t *temp = NULL;

	temp = tree;

	while (temp && temp->left)
		temp = temp->left;

	return (temp);
}



/**
 * bst_remove - program that removes a node with a specified value from a Binary Search Tree (BST)
 *
 * if the node to be removed is found, it is removed using BST removal rules:
 *
 * - if the node is a leaf, it is simply removed
 * - if the node has one child, the node is replaced by its child
 * - if the node has two children, it is replaced by its in-order successor
 *   (minimum value in the right subtree), and then the in-order successor
 *   is removed using the same removal process
 *
 * @root: a pointer to the root node of the BST
 * @value: the value to remove from the BST
 *
 * Return: a pointer to the root node of the BST after removal of the specified value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);

		if (root->left)
			root->left->parent = root;
	}

	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);

		if (root->right)
			root->right->parent = root;
	}

	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}

		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_find_minimum(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);

		if (root->right)
			root->right->parent = root;
	}

	return (root);
}
