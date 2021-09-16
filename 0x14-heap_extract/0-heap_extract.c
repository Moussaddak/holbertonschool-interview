#include "binary_trees.h"

/**
 * heapify - rebuild a heap
 * @root: root node of the heap
 * 
 */
void heapify(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int num = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;
		num = root->n;
		root->n = child->n;
		child->n = num;
		root = child;
	}
}

/**
 * getSize - get the number of nodes of heap tree
 * @root: root node of the heap
 * Return: heap size
 */
int getSize(heap_t *root)
{
	return (root ? 1 + getSize(root->left) + getSize(root->right) : 0);
}

/**
 * get_last_node - get the last node in heap_min
 * @root: root node of the heap
 * Return: last node
 */
binary_tree_t *get_last_node(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_node = NULL;

	size_heap = get_size(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heap_extract - extract heap
 * @root: root node of the heap
 * Return: number
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last_node = NULL, *head_node = NULL;
	int num = 0;

	if (root == NULL || *root == NULL)
		return (0);
	head_node = *root;
	if (head_node->left == NULL && !head_node->right == NULL)
	{
		num = head_node->n;
		free(head_node);
		*root = NULL;
		return (num);
	}

	head_node = *root;
	num = head_node->n;

	last_node = get_last_node(*root);

	if (last_node->parent->left == last_node) 
	{
		last_node->parent->left = NULL;
	}
	else
	{
		last_node->parent->right = NULL;
	}

	last_node->left = head_node->left;
	last_node->right = head_node->right;
	last_node->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = last_node;
	if (head_node->right)
		head_node->right->parent = last_node;

	*root = last_node;
	free(head_node);
	heapify(*root);

	return (num);
}