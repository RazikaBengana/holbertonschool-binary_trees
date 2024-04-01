#include "binary_trees.h"

/**
 * binary_tree_height - program that measures the height of a binary tree
 *
 * this function recursively calculates the height of a binary tree;
 * it compares the height of the left subtree and the right subtree,
 * and adds one to account for the height of the root node itself;
 * the height of a tree is the number of edges on the longest downward
 * path between the root and a leaf
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left >= right)
		return (left + 1);

	return (right + 1);
}



/**
 * current_level - program that applies a function to nodes at a specific level in a binary tree
 *
 * this function recursively traverses the binary tree until it reaches the specified
 * level, at which point it applies the given function to the node's value;
 * it is a utility function used by 'binary_tree_levelorder' to apply a function
 * to all nodes at a specific level
 *
 * @root: a pointer to the root node of the binary tree
 * @level: the level at which to apply the function, starting from 1 for the root node
 * @func: a pointer to a function to call for each node;
 *        the value of the node is passed as a parameter to this function
 *
 * Return: nothing (void)
 */

void current_level(const binary_tree_t *root, size_t level, void (*func)(int))
{
	if (root == NULL)
		return;

	if (level == 1)
		func(root->n);

	else if (level > 1)
	{
		current_level(root->left, level - 1, func);
		current_level(root->right, level - 1, func);
	}
}



/**
 * binary_tree_levelorder - program that applies a function to each node in a binary tree
 * using level-order traversal
 *
 * this function traverses a binary tree in level-order, meaning it visits
 * all the nodes at a given level before moving to the nodes at the next level;
 * it uses the 'binary_tree_height' function to determine the height of the tree
 * and the 'current_level' function to apply the function to all nodes at each
 * level from 1 to the height of the tree;
 * if the tree or func parameter is NULL, the function does nothing
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node;
 *        the value of the node is passed as a parameter to this function
 *
 * Return: nothing (void)
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	h = binary_tree_height(tree);

	if (tree == NULL || func == NULL)
		return;

	for (i = 1; i <= h; i++)
		current_level(tree, i, func);
}
