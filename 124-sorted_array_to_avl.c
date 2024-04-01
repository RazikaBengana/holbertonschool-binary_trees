#include "binary_trees.h"

/**
 * array_to_avl_recursive - program that converts a sorted array to an AVL tree
 *
 * this function recursively builds the AVL tree by finding the middle element of the current
 * segment of the array to ensure a balanced tree and setting it as the root of the current subtree
 *
 * @array: the input sorted array from which the AVL tree is to be created
 * @start_idx: the starting index of the current segment of the array
 * @end_idx: the ending index of the current segment of the array
 * @parent: the parent node for the current node being created. NULL for the root node
 *
 * Return: a pointer to the root node of the AVL tree created from the sorted array segment
 */

avl_t *array_to_avl_recursive(int *array, int start_idx, int end_idx, avl_t *parent)
{
	avl_t *root = NULL;
	int mid_idx;

	if (!array)
		return (NULL);

	if (start_idx > end_idx)
		return (NULL);

	/* Find the middle index of the current segment */
	mid_idx = (start_idx + end_idx) / 2;

	/* Create a new node at the middle index */
	root = binary_tree_node(parent, array[mid_idx]);

	if (!root)
		return (NULL);

	/* Recursively build the left and right subtrees */
	root->left = array_to_avl_recursive(array, start_idx, mid_idx - 1, root);
	root->right = array_to_avl_recursive(array, mid_idx + 1, end_idx, root);

	return (root);
}



/**
 * sorted_array_to_avl - program that converts a sorted array into an AVL tree
 *
 * it serves as a wrapper function that initiates the recursive building of the AVL tree
 *
 * @array: the input sorted array to be converted to an AVL tree
 * @size: the size of the input array
 *
 * Return: a pointer to the root node of the AVL tree, or NULL if the array is empty or NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl_recursive(array, 0, (int)size - 1, NULL));
}
