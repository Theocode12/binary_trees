#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_insert_left - insert node at the left
 * of a binary tree
 * @parent:  a pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: NULL on failure or new_node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
