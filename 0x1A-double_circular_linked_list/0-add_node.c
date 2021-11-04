#include "list.h"
/**
 * 
 * 
 * 
 * 
 */
List *add_node_end(List **list, char *str)
{
    List *node;

    node = malloc(sizeof(list));
    if (!node)
        return (NULL);
    if(!list)
    {
        node->str = strdup(str);
        node->next = NULL;
        node->prev = NULL;
        return (node);
    }
    while ((*list)->next)
        list = &(*list)->next;
    node->str = strdup(str);
    node->next = NULL;
    node->prev = *list;
    return (node);
}
/**
 * add_node_begin - 
 * 
 * 
 */
List *add_node_begin(List **list, char *str) 
{
    List *node;

    node = malloc(sizeof(list));
    if (!node)
        return (NULL);
    if(!list)
    {
        node->str = strdup(str);
        node->next = NULL;
        node->prev = NULL;
        return (node);
    }
    while ((*list)->prev)
        *list = (*list)->prev;
    node->str = strdup(str);
    node->next = *list;
    node->prev = NULL;
    return (node);
}