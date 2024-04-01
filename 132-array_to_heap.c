#include "binary_trees.h"

/**
 * array_to_heap - program that converts an array of integers into a binary heap
 *
 * a binary heap is a complete binary tree where each node's value is greater than
 * or equal to the values of its children, adhering to the heap property;
 * the function iterates over the input array, inserting each element into the heap
 * in the order they appear
 *
 * @array: a pointer to the first element of the array to be converted into a heap
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created heap, or NULL if the array is empty or on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	while (i < size)
	{
		heap_insert(&root, array[i]);
		i++;
	}
	return (root);
}
