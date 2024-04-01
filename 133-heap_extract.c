#include "binary_trees.h"

/**
 * swap_nodes - program that swaps the value of a node with its parent
 *
 * @node: a pointer to the heap node whose value will be swapped with its parent
 *
 * Return: nothing (void)
 */

void swap_nodes(heap_t *node)
{
	int temp_value;

	temp_value = node->n;
	node->n = node->parent->n;
	node->parent->n = temp_value;
}



/**
 * calculate_tree_size - program that calculates the size of a binary tree
 *
 * @tree: a constant pointer to the root node of the tree to calculate the size of
 *
 * Return: the size of the tree as a size_t value
 */

size_t calculate_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = calculate_tree_size(tree->left) + calculate_tree_size(tree->right);

	return (size + 1);
}



/**
 * retrieve_last_node - program that retrieves the last node in a heap
 *
 * @root: a pointer to the root node of the heap
 * @index: the current node index in level order traversal
 * @size: the total size of the heap
 *
 * Return: a pointer to the last node in the heap
 */

heap_t *retrieve_last_node(heap_t *root, size_t index, size_t size)
{
	heap_t *left_child, *right_child;

	if (index == size)
		return (root);

	if (index > size)
		return (NULL);

	left_child = retrieve_last_node(root->left, 2 * index + 1, size);
	right_child = retrieve_last_node(root->right, 2 * index + 2, size);

	if (left_child)
		return (left_child);

	else if (right_child)
		return (right_child);

	else
		return (NULL);
}



/**
 * heap_extract - program that extracts the root node of a max heap
 *
 * @root: a double pointer to the root node of the heap
 *
 * Return: the value of the extracted root node
 */

int heap_extract(heap_t **root)
{
	heap_t *last_node, *current_node = *root;
	size_t tree_size;
	int root_value;

	if (!*root || !root)
		return (0);

	root_value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		(*root) = NULL;
		return (root_value);
	}

	tree_size = calculate_tree_size(*root);
	last_node = retrieve_last_node(*root, 0, tree_size - 1);

	while (current_node->left)
	{
		if (!current_node->right || current_node->left->n > current_node->right->n)
		{
			current_node->n = current_node->left->n;
			current_node = current_node->left;
		}

		else
		{
			current_node->n = current_node->right->n;
			current_node = current_node->right;
		}
	}

	if (last_node->parent->left->n == last_node->n)
		last_node->parent->left = NULL;

	else
		last_node->parent->right = NULL;

	current_node->n = last_node->n;

	for (; current_node && current_node->parent && current_node->n > current_node->parent->n; current_node = current_node->parent)
		swap_nodes(current_node);

	free(last_node);

	last_node = NULL;

	return (root_value);
}
