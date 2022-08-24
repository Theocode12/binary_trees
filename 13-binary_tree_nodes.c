#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return:  number of nodes with at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lfleaves, rtleaves;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);
	lfleaves = binary_tree_nodes(tree->left);
	rtleaves = binary_tree_nodes(tree->right);
	return (1 + lfleaves + rtleaves);
}
