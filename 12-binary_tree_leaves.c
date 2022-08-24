#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree
 * Return: number of leaves in a binary tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lfleaves, rtleaves;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	lfleaves = binary_tree_leaves(tree->left);
	rtleaves = binary_tree_leaves(tree->right);
	return (lfleaves + rtleaves);
}
