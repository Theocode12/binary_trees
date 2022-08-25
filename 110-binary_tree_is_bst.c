#include "binary_trees.h"
#include "limits.h"
/**
 * check_is_bst - checks if binary tree is BST
 * @tree: Binary tree
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if binary tree is BST else 0
 */
int check_is_bst(binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if ((tree->n < min) || tree->n > max)
		return (0);
	return (check_is_bst(tree->left, min, tree->n - 1) &&
			check_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if binary tree is BST else 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_is_bst((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
