#include "binary_trees.h"

/**
 * binary_tree_sibling -  a function that finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * Return: sibling of a node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	if (parent->right == node)
		return (parent->left);
	return (parent->right);
}
