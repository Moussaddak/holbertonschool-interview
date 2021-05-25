#include "lists.h"
/**
 * length_list - count number of nodes in a list
 * @head: a pointer to a list
 * 
 * Return: length of a given list
 */
int length_list(listint_t *head)
{
    int count = 0;

    while (head->next)
    {
        count++;
        head = head->next;
    }
    return (count);
}
/**
 * reverse_list - reverse content of a list
 * @head: pointer to pointer of first node of listint_t list
 * 
 * Return: return a list in reverse
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *curNode, *prevNode;
    
    if (head)
    {
        prevNode = head;
        head = head->next;
        curNode = head;
        prevNode->next = NULL;
        while (head)
        {
            head = head->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = head;
        }
        head = prevNode;
    }
    return (head);
}
/**
 * store_list_value - store value of singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @len: length of listint_t list
 * 
 * Return: pointer to list of stored value
 */
int *store_list_value(listint_t *head, int len)
{
    int  *val_store, *val_add, i = 0;

    val_store =  malloc(len * sizeof(int*));
    if (val_store == NULL)
        return NULL;
    while (head)
    {
        *val_store = (head->n);
        if (!i)
        {
            val_add = val_store;
            i++;
        }
        head = head->next;
        val_store++;

    }
    return val_add;
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * 
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    int *str_val, *str_add, l;

    if (*head == NULL)
        return (1);

    l = length_list(*head);
    str_val = store_list_value(*head, l);
    str_add = str_val;
    *head = reverse_list(*head);

    while (*head)
    {
        if (*str_val != (*head)->n)
        {
            free(str_add);
            return (0);
        }
        str_val++;
        *head = (*head)->next;
    }
    free(str_add);
    return (1);
}