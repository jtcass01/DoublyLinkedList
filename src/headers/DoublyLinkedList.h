
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"

typedef struct {
	Node *head;
	int size;
} DoublyLinkedList;

DoublyLinkedList *dll_createFromArray(int *, int);

DoublyLinkedList *dll_insert(DoublyLinkedList *, unsigned int, int );

DoublyLinkedList *dll_append(DoublyLinkedList *, int);

DoublyLinkedList *dll_removeByValue(DoublyLinkedList *, int);

DoublyLinkedList *dll_removeByIndex(DoublyLinkedList *, int);

void dll_print(DoublyLinkedList *doublyList);

void dll_destroy(DoublyLinkedList *);

#endif