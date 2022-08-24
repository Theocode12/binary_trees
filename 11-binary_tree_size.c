#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree:  pointer to the root node of the tree to measure the size
 * Return: size of a binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lsize = 0, rsize = 0;

	if (!tree)
		return (0);

	lsize = binary_tree_size(tree->left) + 1;
	rsize = binary_tree_size(tree->right) + 1;
	return (lsize + rsize - 1);
}
