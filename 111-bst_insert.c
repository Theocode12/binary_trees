#include "binary_trees.h"
#include <stdlib.h>
/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree:  a double pointer to the root node
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;
	bst_t *tmp_tree;

	if (!tree || !value)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!(*tree))
	{
		*tree = new_node;
		return (new_node);
	}

	tmp_tree = *tree;
	while (tmp_tree)
	{
		if (value > tmp_tree->n)
			if (tmp_tree->right)
				tmp_tree = tmp_tree->right;
			else
			{
				tmp_tree->right = new_node;
				break;
			}
		else if (value < tmp_tree->n)
			if (tmp_tree->left)
				tmp_tree = tmp_tree->left;
			else
			{
				tmp_tree->left = new_node;
				break;
			}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->parent = tmp_tree;
	return (new_node);
}
