/******************************************************************************
* 
* Name: 	Kyle Cheung
* Email: 	kcheu4@uwo.ca
*
* d_linked_list.c contins helper functions for the doubly linked list typedef
*
******************************************************************************/

#include "d_linked_list.h"

d_linked_list_t* init_d_linked_list()
{
	d_linked_list_t *l = (d_linked_list_t*)malloc(sizeof(d_linked_list_t));

	l->size = 0;
	l->head = l->tail = NULL;

	return l;
}

void enqueue(d_linked_list_t *l, void *value)
{
	struct d_node *node = (struct d_node*)malloc(sizeof(struct d_node));

	node->value = value;
	node->prev = node->next = NULL;

	if (l->size == 0)
	{
		l->head = l->tail = node;
	}

	else 
	{
		l->tail->next = node;
		node->prev = l->tail;
		l->tail = node;
	}

	l->size++;
}

void insert_prev(d_linked_list_t *l, struct d_node *n, void *value)
{
	struct d_node *node = (struct d_node*)malloc(sizeof(struct d_node));

	node->value = value;
	node->prev = n->prev;
	node->next = n;

	n->prev->next = node;
	n->prev = node;

	if (l->head == n) l->head = node;
	l->size++;

}

void insert_next(d_linked_list_t *l, struct d_node *n, void *value)
{
	struct d_node *node = (struct d_node*)malloc(sizeof(struct d_node));

	node->value = value;
	node->prev = n;
	node->next = n->next;

	n->next->prev = node;
	n->next = node;

	if (l->tail == n) l->tail = node;
	l->size++;

}

void* dequeue(d_linked_list_t *l)
{
	if (l->size == 0) return NULL;

	void *v = l->head->value;
	struct d_node *n = l->head;

	if (l->size == 1) l->head = l->tail = NULL;
	else l->head = l->head->next;

	l->size--;

	free(n);
	return v;
}

void* pop(d_linked_list_t *l)
{
	if (l->size == 0) return NULL;

	void *v = l->tail->value;
	struct d_node *n = l->tail;

	if (l->size == 1) l->head = l->tail = NULL;
	else l->tail = l->tail->prev;

	l->size--;

	free(n);
	return v;
}

void erase(d_linked_list_t *l,  struct d_node *n)
{
	if (n == l->tail) l->tail = n->prev;
	if (n == l->head) l->head = n->next;

	if (n->prev != NULL) n->prev->next = n->next;
	if (n->next != NULL) n->next->prev = n->prev;
	
	l->size--;

	free(n);
}
