#include "binary_trees.h"

/**
 * binary_tree_node - program that creates a new node in a binary tree
 *
 * @parent: a pointer to the parent node of the node to create;
 *          this parameter can be NULL if the node to create is the root node
 * @value: the value to store in the new node
 *
 * Return: a pointer to the new node, or NULL if memory allocation fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	tmp = malloc(sizeof(binary_tree_t));

	if (tmp == NULL)
		return (NULL);

	tmp->n = value;
	tmp->parent = parent;
	tmp->left = NULL;
	tmp->right = NULL;

	return (tmp);
}
