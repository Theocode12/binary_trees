#include "binary_trees.h"

/**
 * binary_tree_height -  height of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree:  a pointer to the root node
 * Return: 1 on success otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);

	if (lheight == rheight)
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
