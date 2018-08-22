
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"

typedef struct {
	Node *head;
	int size;
} DoublyLinkedList;

void createFromArray(int *array, int array_size);

void insert(void);

void append(void);

void removeByValue(void);

void removeByIndex(void);

void print(void);

void destroy(void);

#endif