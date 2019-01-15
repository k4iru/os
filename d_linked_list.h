/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* linked_list.h cotains the defenitions for the linked_list struct
*
******************************************************************************/

#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

#include "stdlib.h"

struct d_node
{
	void *value;
	struct d_node *prev, *next;
};

typedef struct
{
	struct d_node *head, *tail;
	int size;
} d_linked_list_t;

d_linked_list_t* init_d_linked_list();
void enqueue(d_linked_list_t*, void*);
void insert_prev(d_linked_list_t*, struct d_node*, void*);
void insert_next(d_linked_list_t*, struct d_node*, void*);
void* dequeue(d_linked_list_t*);
void* pop(d_linked_list_t*);
void erase(d_linked_list_t*,  struct d_node*);

#endif