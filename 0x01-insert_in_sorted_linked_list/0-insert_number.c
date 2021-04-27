#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of a node of listint_t list
 * @number: int number to insert
 * return: address of new node or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current, *prev, *new;

    if (*head == NULL)
    {
        new = add_nodeint_end(&(*head), number);
    }
    else
    {
        current = *head;
        prev = NULL;
        while (current && current->n < number)
        {
            prev = current;
            current = current->next;
        }
        new = malloc(sizeof(listint_t));
        if (new == NULL)
            return (NULL);
        new->n = number;
        if (current)
            new->next = current;
        else
            new->next = NULL;
        prev->next = new;
    }
    return (new);
}