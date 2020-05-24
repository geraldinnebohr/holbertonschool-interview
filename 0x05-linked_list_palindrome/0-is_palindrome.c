#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_length - Get the length of a linked list
 * @head: linked list head
 * Return: lenght
 */

int list_length(listint_t **head)
{
	int i;
	listint_t *current = *head;

	for (i = 0; current != NULL; i++)
		current = current->next;
	return (i);
}

/**
 * add_nodeint - function that adds a new node at the beginning of a list
 * @head: double pointer
 * @n: is an integer
 * Return: Address of the new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (*head);

}

/**
 * is_palindrome - checks if a linked list is palindrome
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length = list_length(head);
	int half_length = length / 2;
	int i, if_palindrome = 1;
	listint_t *reversed_head = NULL;
	listint_t *current = *head;
	listint_t *current_reversed;

	for (i = 0; i < half_length; i++)
		current = current->next;
	while (current != NULL)
	{
		reversed_head = add_nodeint(&reversed_head, current->n);
		current = current->next;
	}
	current_reversed = reversed_head;
	current = *head;
	while (current_reversed != NULL)
	{
		if (current_reversed->n != current->n)
			if_palindrome = 0;
		current_reversed = current_reversed->next;
		current = current->next;
	}
	printf("%d", half_length);
	return (if_palindrome);
}
