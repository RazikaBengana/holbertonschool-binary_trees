#include "binary_trees.h"

/**
 * binary_tree_insert_right - program that inserts a node as the right-child of another node in a binary tree
 *
 * @parent: a pointer to the parent node where the new node is to be inserted as the right child
 * @value: the value to store in the new node
 *
 * Return: a pointer to the newly created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right == NULL)
		parent->right = new;
	else
	{
		new->right = parent->right;
		parent->right = new;
	}
	return (new);
}
