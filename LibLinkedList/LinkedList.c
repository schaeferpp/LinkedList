#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

inline int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}

/**
 * Run with the list->runner to the position
 */
void run(plinked_list list, int position)
{
	int i;
	int diff1, diff2, diff3, min;
	short int num;

	diff1 = position;
	diff2 = list->runnerpos - position;
	diff3 = list->size - position;

	min = abs(diff1);
	num = 1;
	if (abs(diff2) < min)
	{
		min = abs(diff2);
		num = 2;
	}
	if (abs(diff3) < min)
	{
		min = abs(diff3);
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
		for (i = list->size-1; i > position; i--)
		{
			list->runner = list->runner->previous;
		}
		break;
	}
	list->runnerpos = position;
}

extern void list_append(plinked_list list, void* value)
{
	pnode newnode;
	newnode = malloc(sizeof(node_t));
	newnode->content = value;
	newnode->previous = list->last;
	newnode->next = NULL;
	if(list->size>0)
	{
		list->last->next = newnode;
	}
	else 
	{
		list->head = newnode;
	}	
	list->last = newnode;
	list->size++;
	return;
}

extern void list_insert(plinked_list list, int position, void* value)
{
	pnode newnode;

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

extern void list_remove(plinked_list list, int position)
{
	if(position < 0 || position >= list->size)
	{
		return;
	}
	
	run(list, position);
	list->runner->previous->next = list->runner->next;
	list->runner->next->previous = list->runner->previous;
}

extern void* list_get(plinked_list list, int position)
{
	if(position >= list->size || position < 0) 
	{	
		return NULL;
	}
	run(list, position);
	return list->runner->content;
}

extern void list_add_all(plinked_list list, void** elems, int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		list_append(list, elems[i]);
	}
	return;
}

extern plinked_list list_new()
{
	plinked_list list = malloc(sizeof(linked_list_t));
	
	list->head = NULL;
	list->last = NULL;
	list->runner = NULL;
	list->size = 0;
	list->runnerpos = 0;
	return list;
}
