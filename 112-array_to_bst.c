#include "binary_trees.h"

/**
 * array_to_bst - program that converts an array to a binary search tree (BST)
 *
 * this function takes an array of integers and its size, then constructs
 * a binary search tree (BST) by inserting each element of the array into the BST;
 * if a duplicate value is found during the insertion process, it stops and returns
 * NULL, ensuring each value in the BST is unique;
 * if the array is NULL, the function also returns NULL
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
			{}

			if (j == i)
				return (NULL);
		}
	}

	return (tree);
}