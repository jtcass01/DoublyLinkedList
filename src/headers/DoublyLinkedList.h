
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"

typedef struct {
	Node *head;
	int size;
} DoublyLinkedList;

DoublyLinkedList *createFromArray(int *, int);

DoublyLinkedList *insert(DoublyLinkedList *, unsigned int, int );

void append(DoublyLinkedList *, int);

void removeByValue(void);

void removeByIndex(void);

void printDLList(DoublyLinkedList *doublyList);

void destroyDLList(DoublyLinkedList *);

#endif