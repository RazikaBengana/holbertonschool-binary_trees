#include "binary_trees.h"

/**
 * balanceAVLTree - program that balances an AVL tree to maintain the AVL tree properties
 *
 * @tree: a double pointer to the root node of the AVL tree
 *
 * Return: nothing (void)
 */

void balanceAVLTree(avl_t **tree)
{
	int balanceValue;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balanceAVLTree(&(*tree)->left);
	balanceAVLTree(&(*tree)->right);

	balanceValue = binary_tree_balance((const binary_tree_t *)*tree);

	if (balanceValue > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);

	else if (balanceValue < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}




/**
 * findSuccessor - program that finds the successor of a given node in a BST
 *
 * @node: a pointer to the current node
 *
 * Return: the value of the successor node
 */

int findSuccessor(bst_t *node)
{
	int leftMostValue;

	if (node == NULL)
	{
		return (0);
	}

	else
	{
		leftMostValue = findSuccessor(node->left);

		if (leftMostValue == 0)
		{
			return (node->n);
		}

		return (leftMostValue);
	}
}




/**
 * handleNodeRemoval - program that handles node removal based on the type of node
 * (leaf, single child, two children)
 *
 * @nodeToRemove: a pointer to the node to be removed
 *
 * Return: the value to replace in the parent node if needed
 */

int handleNodeRemoval(bst_t *nodeToRemove)
{
	int replacementValue = 0;

	if (!nodeToRemove->left && !nodeToRemove->right) /* Leaf node */
	{
		if (nodeToRemove->parent->right == nodeToRemove)
			nodeToRemove->parent->right = NULL;

		else
			nodeToRemove->parent->left = NULL;

		free(nodeToRemove);

		return (0);
	}

	else if ((!nodeToRemove->left && nodeToRemove->right) || (!nodeToRemove->right && nodeToRemove->left)) /* Single child */
	{
		if (!nodeToRemove->left) /* Right child only */
		{
			if (nodeToRemove->parent->right == nodeToRemove)
				nodeToRemove->parent->right = nodeToRemove->right;

			else
				nodeToRemove->parent->left = nodeToRemove->right;

			nodeToRemove->right->parent = nodeToRemove->parent;
		}

		if (!nodeToRemove->right) /* Left child only */
		{
			if (nodeToRemove->parent->right == nodeToRemove)
				nodeToRemove->parent->right = nodeToRemove->left;

			else
				nodeToRemove->parent->left = nodeToRemove->left;

			nodeToRemove->left->parent = nodeToRemove->parent;
		}

		free(nodeToRemove);

		return (0);
	}

	else /* Two children */
	{
		replacementValue = findSuccessor(nodeToRemove->right);
		nodeToRemove->n = replacementValue;

		return (replacementValue);
	}
}




/**
 * bst_remove - program that removes a node from a BST based on its value
 *
 * @root: a pointer to the root of the BST
 * @value: the value of the node to be removed
 *
 * Return: a pointer to the root of the BST after removal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int removalResult = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)
	{
		removalResult = handleNodeRemoval(root);

		if (removalResult != 0)
			bst_remove(root->right, removalResult);
	}

	else
		return (NULL);

	return (root);
}




/**
 * avl_remove - program that removes a node from an AVL tree and rebalances the tree
 *
 * @root: a pointer to the root of the AVL tree
 * @value: the value of the node to be removed
 *
 * Return: a pointer to the root of the AVL tree after removal and rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *updatedRoot = (avl_t *) bst_remove((bst_t *) root, value);

	if (updatedRoot == NULL)
		return (NULL);

	balanceAVLTree(&updatedRoot);

	return (updatedRoot);
}
