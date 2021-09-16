#ifndef HEAP_EXTRACT_H
#define HEAP_EXTRACT_H

/*-----------LIBRARY----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);

int heap_extract(heap_t **root);

#endif /* HEAP_EXTRACT_H */