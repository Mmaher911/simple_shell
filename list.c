#include "ssh.h"

/**
 * add_node_end - Adds a new node to the end of a linked list.
 * @head: The linked list to add to.
 * @str: The string to add to the linked list.
 * Return: The number of elements in the linked list.
 */
lpath *add_node_end(lpath **head, char *str)
{
	lpath *n;
	lpath *c;
	int a;

	n = malloc(sizeof(lpath));
	if (n == NULL)
		return (NULL);

	if (*head != NULL)
	{
		c = *head;
		for (a = 0; c->next != NULL; a++)
		{
			c = c->next;
		}
		c->next = n;
	}
	else
		*head = n;

	n->next = NULL;
	n->dir = _strdup(str);
	n->len = _strlen(str);
	return (n);
}

/**
 * free_list - Frees all elements of a linked list.
 * @head: The linked list to free.
 * Return: void
 */
void free_list(lpath *head)
{
	if (head != NULL)
	{
		free_list(head->next);
		free(head->dir);
		free(head);
	}
}
