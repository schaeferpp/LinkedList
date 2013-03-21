#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
	
/**
* Represents the data node. Pointer to following and previous node are stored.
*/
struct node
{
	struct node* next;
	struct node* previous;
	void* content;
};

typedef struct node node_t;

typedef node_t* pnode;

/**
 * Represents the actual list. Three pointers are defined: head, last and a runner.
 * runnerpos defines the current index of the node* runner.
 * size defines the current size of the list.
 */
struct linked_list
{
	/**
	 * Pointer to the first element of the list.
	 */
	pnode head;
	/**
	 * Pointer to the last element of the list.
	 */
	pnode last;
	/**
	 * Pointer to some element of the list. The current position is specified in runnerpos.
	 */
	pnode runner;
	/**
	 * Defines the current position of runner.
	 */
	int runnerpos;
	/**
	 * Stores the list's current number of elements.
	 */
	int size;
};

typedef struct linked_list linked_list_t;

typedef linked_list_t* plinked_list;

/**
 * Appends value to the end of the list.
 */
void list_append(plinked_list list, void* value);

/**
 * Inserts value into the list at the specified position. The current object at position
 * will be at (position+1) after this operation.
 */
void list_insert(plinked_list list, int position, void* value);

/**
 * Removes the element of the list at the specified position.
 */
void list_remove(plinked_list list, int position);

/**
 * Returns a pointer to the object at position.
 */
void* list_get(plinked_list list, int position);

/**
 * Inserts all elements of elems into the list. count has to be defined.
 */
void list_add_all(plinked_list list, void** elems, int count);

/**
 * Initializes an empty list. Works like an constructor.
 */
plinked_list init_list();

#endif
