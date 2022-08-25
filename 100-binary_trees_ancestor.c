#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: dept of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth  = 0;

	if (!tree)
		return (0);
	if (!(tree->parent))
		return (0);
	depth = binary_tree_depth(tree->parent) + 1;
	return (depth);
}

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return:  ancestor of two nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t dp_first, dp_second;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	dp_first = binary_tree_depth(first);
	dp_second = binary_tree_depth(second);

	if (dp_first > dp_second)
		return (binary_trees_ancestor(first->parent, second));

	if (dp_first < dp_second)
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));
}
