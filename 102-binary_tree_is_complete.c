#include "binary_trees.h"
#include <stdlib.h>
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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 on success else 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front, end, flag = 0;
	binary_tree_t **queue, *node;

	if (!tree)
		return (0);

	/*creates queue for level order trasversal*/
	queue = create_queue(&front, &end);
	enqueue(queue, (binary_tree_t *)tree, &end);

	while ((node = deque(queue, &front)))
	{
		if (node->left)
		{
			/* if flag is true it means we've encountered an empty right node*/
			if (flag)
			{
				free(queue);
				return (0);
			}

			enqueue(queue, (binary_tree_t *)node->left, &end);
		}
		else
			flag = 1;

		if (node->right)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			enqueue(queue, (binary_tree_t *)node->right, &end);
		}
		else
			flag = 1;
	}
	free(queue);
	return (1);
}
