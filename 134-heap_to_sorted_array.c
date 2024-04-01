#include "binary_trees.h"

/**
 * heap_to_sorted_array - program that converts a heap into a sorted array
 *
 * this function takes a heap and its size, extracts elements from the heap, and places
 * them into an array in sorted order;
 * the sorted order is determined by the nature of the heap (max-heap or min-heap);
 * for a max-heap, the result will be in descending order, while for a min-heap,
 * it will be in ascending order
 *
 * the function works by repeatedly extracting the root of the heap (which is either
 * the maximum or minimum element, depending on the heap type) and placing that
 * element into the array;
 * this process is repeated until the heap is empty
 *
 * @heap: a pointer to the heap from which to extract elements
 * @size: a pointer to a size_t variable where the size of the created array will be stored;
 *        this reflects the number of elements in the heap
 *
 * Return: a pointer to the created array containing the sorted elements,
 *         or NULL if the heap is NULL or if memory allocation fails
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extract, i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);

	heap_size = binary_tree_size(heap);

	*size = heap_size;

	array = malloc(heap_size * sizeof(int));

	if (!array)
		return (NULL);

	while (heap)
	{
		extract = heap_extract(&heap);
		array[i] = extract;
		i++;
	}

	return (array);
}
