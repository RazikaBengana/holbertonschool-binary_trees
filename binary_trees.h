#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>



/**
 * struct binary_tree_s - a structure for a basic binary tree
 *
 * this structure defines a node within a binary tree;
 * each node has an integer value and pointers to its
 * parent node as well as its left and right children;
 *
 * a binary tree is a data structure in which each node
 * has at most two children, referred to as the left child
 * and the right child
 *
 * @n: the integer value stored in the node
 * @parent: a pointer to the parent of the node. NULL for the root node
 * @left: a pointer to the left child of the node. NULL if no left child
 * @right: a pointer to the right child of the node. NULL if no right child
 */

struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};



typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;



/* ---------------------------------------------------------------- */


/* function provided */
void binary_tree_print(const binary_tree_t *);


/* ---------------------------------------------------------------- */


/* task 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* task 1 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* task 2 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* task 3 */
void binary_tree_delete(binary_tree_t *tree);

/* task 4 */
int binary_tree_is_leaf(const binary_tree_t *node);

/* task 5 */
int binary_tree_is_root(const binary_tree_t *node);

/* task 6 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* task 7 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* task 8 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* task 9 */
size_t binary_tree_height(const binary_tree_t *tree);

/* task 10 */
size_t binary_tree_depth(const binary_tree_t *tree);

/* task 11 */
size_t binary_tree_size(const binary_tree_t *tree);

/* task 12 */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* task 13 */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* task 14 */
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/* task 15 */
int binary_tree_is_full(const binary_tree_t *tree);

/* task 16 */
int level_match(int a, int b);
int is_perfect(binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/* task 17 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* task 18 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);




/* advanced tasks */
/* ---------------------------------------------------------------- */


/* task 100 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);

/* task 101 */
size_t binary_tree_height(const binary_tree_t *tree);
void current_level(const binary_tree_t *root, size_t level, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* task 102 */
size_t binary_tree_size(const binary_tree_t *tree);
int is_tree_complete(const binary_tree_t *tree, size_t i, size_t size);
int binary_tree_is_complete(const binary_tree_t *tree);

/* task 103 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* task 104 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);


/* ---------------------------------------------------------------- */


/* task 110 */
int is_valid_BST_helper(const binary_tree_t *tree, int *prev);
int binary_tree_is_bst(const binary_tree_t *tree);

/* task 111 */
bst_t *bst_insert_recursion(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);

/* task 112 */
bst_t *array_to_bst(int *array, size_t size);

/* task 113 */
bst_t *bst_search(const bst_t *tree, int value);

/* task 114 */
bst_t *bst_find_minimum(bst_t *tree);
bst_t *bst_remove(bst_t *root, int value);


/* ---------------------------------------------------------------- */


/* task 120 */
int calculateHeightRecursively(const binary_tree_t *tree);
int calculateTreeHeight(const binary_tree_t *tree);
int checkIfAVL(const binary_tree_t *tree, int minValue, int maxValue);
int binary_tree_is_avl(const binary_tree_t *tree);

/* task 121 */
avl_t *recursive_insert_node(avl_t **tree, avl_t *parent, avl_t **newNode, int newValue);
avl_t *avl_insert(avl_t **tree, int value);

/* task 122 */
avl_t *array_to_avl(int *array, size_t size);

/* task 123 */
void balanceAVLTree(avl_t **tree);
int findSuccessor(bst_t *node);
int handleNodeRemoval(bst_t *nodeToRemove);
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);

/* task 124 */
avl_t *array_to_avl_recursive(int *array, int start_idx, int end_idx, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);


/* ---------------------------------------------------------------- */


/* task 130 */
size_t binary_tree_size(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int index, int total_nodes);
int binary_tree_is_complete(const binary_tree_t *tree);
int check_heap_property(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

/* task 131 */
size_t max_size_t(size_t a, size_t b);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
heap_t *binary_tree_complete_insert(heap_t *tree, int value);
heap_t *heap_insert(heap_t **root, int value);

/* task 132 */
heap_t *array_to_heap(int *array, size_t size);

/* task 133 */
void swap_nodes(heap_t *node);
size_t calculate_tree_size(const binary_tree_t *tree);
heap_t *retrieve_last_node(heap_t *root, size_t index, size_t size);
int heap_extract(heap_t **root);

/* task 134 */
int *heap_to_sorted_array(heap_t *heap, size_t *size);



#endif
