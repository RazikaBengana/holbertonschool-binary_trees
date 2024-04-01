#include "binary_trees.h"

/**
 * max_size_t - program that calculates the maximum of two size_t values
 *
 * @a: the first size_t value to compare
 * @b: the second size_t value to compare
 *
 * Return: the larger of the two size_t values
 */

size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}




/**
 * binary_tree_height - program that calculates the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if the tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}




/**
 * binary_tree_nodes - program that counts the total nodes in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the nodes
 *
 * Return: the total number of nodes in the tree, or 0 if the tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}




/**
 * binary_tree_is_perfect - program that checks if a binary tree is perfect
 *
 * a binary tree is perfect if all levels are completely filled
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, i, pow2 = 1;
	size_t total_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	total_nodes = binary_tree_nodes(tree);

	for (i = 0; i < height; i++)
		pow2 *= 2;

	return (pow2 - 1 == (int)total_nodes);
}




/**
 * binary_tree_complete_insert - program that inserts a value into a complete binary tree
 *
 * this function ensures the tree remains complete after insertion
 *
 * @tree: a pointer to the root node of the tree where the value is to be inserted
 * @value: the value to insert into the tree
 *
 * Return: a pointer to the new node after insertion, or NULL on failure
 */

heap_t *binary_tree_complete_insert(heap_t *tree, int value)
{
	heap_t *new = NULL;

	if (tree->left && tree->right)
	{
		if (!binary_tree_is_perfect(tree) &&
		    binary_tree_is_perfect(tree->left))

			new = binary_tree_complete_insert(tree->right, value);

		else
			new = binary_tree_complete_insert(tree->left, value);
	}

	else
	{
		new = binary_tree_node(tree, value);

		if (!new)
			return (NULL);

		if (!(tree->left))
			tree->left = new;
		else
			tree->right = new;
	}

	return (new);
}




/**
 * heap_insert - program that inserts a value into a heap
 *
 * this function maintains the heap property after insertion by swapping nodes if necessary
 *
 * @root: a double pointer to the root node of the heap
 * @value: the value to insert into the heap
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *temp = NULL;
	int swap;

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);

		if (!new)
			return (NULL);

		*root = new;

		return (new);
	}

	new = binary_tree_complete_insert(*root, value);

	if (!new)
		return (NULL);

	temp = new;

	while (temp && temp->parent && temp->n > temp->parent->n)
	{
		swap = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = swap;
		temp = temp->parent;
	}

	return (temp);
}
