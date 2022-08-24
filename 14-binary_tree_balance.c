#include "binary_trees.h"
#include <stdio.h>

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
 * binary_tree_balance -  measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: he balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (!tree)
		return (0);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);
	printf("%ld    %ld\n", lheight, rheight);
	return (lheight - rheight);
}
