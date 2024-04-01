#include "binary_trees.h"

/**
 * binary_tree_size - program that calculates the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size of
 *
 * Return: the total number of nodes in the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}



/**
 * tree_is_complete - program that checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 * @index: the current node index in the tree, starting from 0 for the root
 * @total_nodes: the total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int index, int total_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= total_nodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * index) + 1, total_nodes) &&
		tree_is_complete(tree->right, (2 * index) + 2, total_nodes));
}



/**
 * binary_tree_is_complete - program that determines if a binary tree is complete
 *
 * @tree: a pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t total_nodes;

	if (tree == NULL)
		return (0);

	total_nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, total_nodes));
}



/**
 * check_heap_property - program that checks if all nodes in the binary tree satisfy the heap property
 *
 * @tree: a pointer to the current node of the tree being checked
 *
 * Return: 1 if all nodes satisfy the heap property, 0 otherwise
 */

int check_heap_property(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_heap_property(tree->left) && check_heap_property(tree->right));
}



/**
 * binary_tree_is_heap - program that determines if a binary tree is a max heap
 *
 * @tree: a pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid max heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_heap_property(tree->left) && check_heap_property(tree->right));
}
