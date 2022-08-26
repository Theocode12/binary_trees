#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing the value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || !value)
		return (NULL);

	while (tree)
	{
		if (value > tree->n)
		{
			if (tree->right)
				tree = tree->right;
			else
				break;
		}

		else if (value < tree->n)
		{
			if (tree->left)
				tree = tree->left;
			else
				break;
		}

		else
			return ((bst_t *)tree);
	}
	return (NULL);
}
