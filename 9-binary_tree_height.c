#include "binary_trees.h"

/**
 * binary_tree_height -  height of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (left > right ? left + 1 : right + 1);
}
