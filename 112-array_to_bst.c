#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array
 * @size: number of element in the array
 * Return: root of the binary tree
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
