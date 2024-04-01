#include "binary_trees.h"

/**
 * bst_insert_recursion - program that inserts a value into a Binary Search Tree (BST) recursively
 *
 * this function assumes the tree is a valid BST at all times
 *
 * @tree: the root node of the BST where the value will be inserted
 * @value: the value to insert into the BST
 *
 * Return: the new node created with the given value, or NULL if the value already exists in the BST
 */

bst_t *bst_insert_recursion(bst_t *tree, int value)
{
	bst_t *new = NULL;

	if (tree->n > value)
	{
		if (tree->left == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->left = new;
			return (new);
		}

		return (bst_insert_recursion(tree->left, value));
	}

	if (tree->n < value)
	{
		if (tree->right == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->right = new;
			return (new);
		}

		return (bst_insert_recursion(tree->right, value));
	}

	return (NULL);
}



/**
 * bst_insert - public insertion function that inserts a value into a Binary Search Tree (BST)
 *
 * this function handles the case when the tree is empty and initializes it with the given value
 *
 * @tree: double pointer to the root node of the BST to insert the value into
 * @value: the value to be inserted into the BST
 *
 * Return: the new node created with the given value, or NULL if the value already exists in the BST
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

	if (!tree || !(*tree))
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	return (bst_insert_recursion(*tree, value));
}
