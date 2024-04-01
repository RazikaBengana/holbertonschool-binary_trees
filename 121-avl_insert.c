#include "binary_trees.h"

/**
 * recursive_insert_node - program that recursively inserts a node into an AVL tree
 *
 * this function ensures the tree remains balanced after insertion, performing necessary rotations
 *
 * @tree: a pointer to the root of the AVL tree
 * @parent: a pointer to the parent node of the node being inserted
 * @newNode: a double pointer to the new node to be inserted
 * @newValue: the value to be stored in the new node
 *
 * Return: the new root of the AVL tree after insertion and rebalancing
 */

avl_t *recursive_insert_node(avl_t **tree, avl_t *parent, avl_t **newNode, int newValue)
{
	int balanceValue;

	if (*tree == NULL)
		return (*newNode = binary_tree_node(parent, newValue));

	if ((*tree)->n > newValue)
	{
		(*tree)->left = recursive_insert_node(&(*tree)->left, *tree, newNode, newValue);

		if ((*tree)->left == NULL)
			return (NULL);
	}

	else if ((*tree)->n < newValue)
	{
		(*tree)->right = recursive_insert_node(&(*tree)->right, *tree, newNode, newValue);

		if ((*tree)->right == NULL)
			return (NULL);
	}

	else
	{
		return (*tree);
	}

	balanceValue = binary_tree_balance(*tree);

	if (balanceValue > 1 && (*tree)->left->n > newValue)
	{
		*tree = binary_tree_rotate_right(*tree);
	}

	else if (balanceValue > 1 && (*tree)->left->n < newValue)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}

	else if (balanceValue < -1 && (*tree)->right->n < newValue)
	{
		*tree = binary_tree_rotate_left(*tree);
	}

	else if (balanceValue < -1 && (*tree)->right->n > newValue)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}



/**
 * avl_insert - program that inserts a new node into an AVL tree
 *
 * this is the public insertion function that starts the recursive insertion process;
 * it creates a new node and inserts it into the AVL tree, ensuring the tree remains balanced
 *
 * @tree: a double pointer to the root of the AVL tree
 * @value: the value for the new node
 *
 * Return: a pointer to the newly inserted node, or NULL if insertion failed
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	recursive_insert_node(tree, *tree, &newNode, value);

	return (newNode);
}
