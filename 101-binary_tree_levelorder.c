#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_QUEUE 500

/**
 * create_queue - create a queue object
 * @front: intialise front of the queue
 * @end: initialize end of the queue
 * Return: queue object
 */

binary_tree_t **create_queue(int *front, int *end)
{
	binary_tree_t **queue;

	queue = calloc(MAX_QUEUE, sizeof(binary_tree_t *));
	*front = *end = 0;
	return (queue);
}

/**
 * enqueue - adds a node to the end of a queue
 * @queue: Queue
 * @node: node to enqueue
 * @end: place to enque
 */
void enqueue(binary_tree_t **queue, binary_tree_t *node, int *end)
{
	queue[*end] = node;
	(*end)++;
}

/**
 * deque - pop a node from the begining of a queue
 * @queue: Queue
 * @front: a pointer to the front if the queue
 * Return: a node from the queue
 */
binary_tree_t *deque(binary_tree_t **queue, int *front)
{
	return (queue[(*front)++]);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front, end;
	binary_tree_t **queue, *node;

	if (!tree || !func)
		return;
	queue = create_queue(&front, &end);
	node = (binary_tree_t *)tree;
	while (node)
	{
		func(node->n);

		if (node->left)
			enqueue(queue, node->left, &end);

		if (node->right)
			enqueue(queue, node->right, &end);

		node = deque(queue, &front);
	}
	free(queue);
}
