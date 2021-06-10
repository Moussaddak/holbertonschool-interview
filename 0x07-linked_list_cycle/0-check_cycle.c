#include "lists.h"
#include <stdio.h>
/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to head of list
 * 
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *node1, *node2;

    node1 = list;
    node2 = list;

    while (node2 && node2->next)
    {
        node1 = node1->next;
        node2 = node2->next->next;
        if (node1 == node2)
            return (1);
    }
    return (0);

}