#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Run with the list->runner to the position
 */
void run(linked_list_t list, int position)
{
	int i;
	int diff1, diff2, diff3, min;
	short int num;

	diff1 = list->size - position;
	diff2 = list->runnerpos - position;
	diff3 = position;

	min = abs(diff1);
	num = 1;
	if (abs(diff2) < min)
	{
		min = diff2;
		num = 2;
	}
	if (abs(diff3) < min)
	{
		min = diff3;
		num = 3;
	}

	switch (num)
	{
	case 1: // am nächsten an first
		list->runner = list->head;
		for (i = 0; i < position; i++)
		{
			list->runner = list->runner->next;
		}
		break;
	case 2:
		// insert VOR runner
		if ((list->runnerpos - position) > 0)
		{
			for (i = list->runnerpos; i > position; i--)
			{
				list->runner = list->runner->previous;
			}
		}
		// insert NACH runner
		else
		{
			for (i = list->runnerpos; i < position; i++)
			{
				list->runner = list->runner->next;
			}
		}
		break;
	case 3: // am nächsten an last
		list->runner = list->last;
		for (i = 0; i > position; i--)
		{
			list->runner = list->runner->previous;
		}
		break;
	}
}

void list_append(linked_list_t list, char* value)
{
	node_t newnode;
	newnode = malloc(sizeof(struct node));

	newnode->content = value;
	newnode->previous = list->last;
	newnode->next = NULL;

	list->last->next = newnode;
	list->last = newnode;
	list->size++;

	return;
}

inline int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}

void list_insert(linked_list_t list, int position, char* value)
{
	node_t newnode;

	newnode = malloc(sizeof(struct node));
	newnode->content = value;

	if (position >= list->size)
	{
		list_append(list, value);
		return;
	}

	run(list, position);

	newnode->next = list->runner;
	newnode->previous = list->runner->previous;
	list->runner->previous->next = newnode;
	list->runner->previous = newnode;

	list->runnerpos = position + 1;
	list->size++;
}

void list_remove(linked_list_t list, int position)
{

}

char* list_get(linked_list_t list, int position)
{
	run(list, position);
	return list->runner->content;
}

void list_add_all(linked_list_t list, char** elems)
{
	return;
}
