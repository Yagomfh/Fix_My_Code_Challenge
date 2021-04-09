#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp = *head;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }
    saved_head = *head;
    p = 0;
    while (p < index && tmp != NULL)
    {
        tmp = tmp->next;
        p++;
    }
    if (p != index)
    {
        *head = saved_head;
        return (-1);
    }
    if (0 == index)
    {
        tmp = tmp->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        saved_head = tmp;
        tmp->prev->next = tmp->next;
        if (tmp->next)
            tmp->next->prev = tmp->prev;
        free(saved_head);
    }
    return (1);
}
