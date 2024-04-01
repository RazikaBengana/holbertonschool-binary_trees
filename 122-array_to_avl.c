#include "binary_trees.h"

/**
 * array_to_avl - program that converts an array of integers into an AVL
 * (Adelson-Velsky and Landis) tree
 *
 * this function iteratively inserts elements from the array into the AVL tree
 * maintaining the AVL tree properties;
 * it remains balanced where the heights of two child subtrees of any node differ
 * by no more than one
 *
 * @array: a pointer to the first element of the array of integers to be converted
 * @size: the total number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 *         or NULL if the array is NULL or the tree cannot be created
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	avl_t *root = NULL;

	if (!array)
		return (NULL);

	while (i < size)
	{
		avl_insert(&root, array[i]);
		i++;
	}

	return (root);
}
