#include "binary_trees.h"

/**
 * level_match - helper function used in calculating whether a binary tree is perfect
 *
 * this function compares two integers (levels or heights) and returns
 * the incremented value of 'a' if they are equal, indicating the level
 * is consistent across both path
 *
 *
 * @a: an integer representing the level or height from one path of the tree
 * @b: an integer representing the level or height from another path of the tree
 *
 * Return: the incremented value of 'a' if 'a' and 'b' are equal, 0 otherwise
 */

int level_match(int a, int b)
{
	if (a == b)
		return (a + 1);

	return (0);
}



/**
 * is_perfect - auxiliary function to assist in checking if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the subtree to check for perfection
 *
 * Return: the level of the deepest node if the tree is perfect, 0 otherwise
 */

int is_perfect(binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = is_perfect(tree->left);
	right = is_perfect(tree->right);

	return (level_match(left, right));
}



/**
 * binary_tree_is_perfect - program that checks if a binary tree is perfect
 *
 * a perfect binary tree is a type of binary tree in which every internal node
 * has exactly two child nodes and all the leaf nodes are at the same level
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->right != NULL)
		return (is_perfect(tree->left) == is_perfect(tree->right));

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (0);
}
