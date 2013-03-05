#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

typedef struct node
{
	struct node* next;
	struct node* previous;
	char* content;
} *node_t;

//typedef node* node_t;

typedef struct
{
	node_t head;
	node_t last;
	node_t runner;
	int runnerpos;
	int size;
} linked_list;

typedef linked_list* linked_list_t;

void list_append(linked_list_t list, char* value);

void list_insert(linked_list_t list, int position, char* value);

void list_remove(linked_list_t list, int position);

char* list_get(linked_list_t list, int position);

void list_add_all(linked_list_t list, char** elems);

#endif
