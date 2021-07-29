#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root;
    size_t middle;

    root = NULL;

    if (size == 0)
        return (NULL);

    middle = (size % 2 == 0) ? (size / 2) - 1 : (size / 2);

    root = binary_tree_node(root, array[middle]);

    create_tree(&root, array, middle, Left);
    create_tree(&root, array + middle + 1, (size - 1 - middle), Right);

    return (root);
}
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent address of new node
 * @value: int value to be stored in the node
 * Return: return a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
    {
        return (NULL);
    }
    if (!parent)
    {
        new_node->parent = NULL;
    }
    else
    {
        new_node->parent = parent;
    }
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}
/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: Left to add node on the left, Right to add node on the right
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
    size_t middle;

    if (size == 0)
        return;

    middle = (size % 2 == 0) ? (size / 2) - 1 : (size / 2);

    if (mode == 1)
    {
        (*node)->left = binary_tree_node(*node, array[middle]);
        create_tree(&((*node)->left), array, middle, Left);
        create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), Right);
    }
    else
    {
        (*node)->right = binary_tree_node(*node, array[middle]);
        create_tree(&((*node)->right), array, middle, Left);
        create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), Right);
    }
}