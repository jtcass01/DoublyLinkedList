/*
** File:         test.c
** Author:       Jacob Taylor Cassady
** Description:  
** Last Updated: 8/21/18
*/

/* Compiler/OS Headers */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/* User Created Headers */
#include "../headers/DoublyLinkedList.h"
#include "../headers/Node.h"

DoublyLinkedList *createFromArray(int *array, int array_size){
	DoublyLinkedList *doublyList = malloc(sizeof(Node[array_size]) + sizeof(int));
	doublyList->size = array_size;

	Node *previousNode = NULL;
	Node *nextNode = NULL;
	int array_value = 0;

	for(unsigned int array_index = 0; array_index < array_size; array_index++){
		array_value = *(array + array_index);
		if(array_index == 0){
			doublyList->head = createNode(array_value, NULL);
			previousNode = doublyList->head;
		} else {
			nextNode = createNode(array_value, previousNode);
			previousNode->nextNode = nextNode;
			previousNode = nextNode;
		}
	}
	previousNode->nextNode = NULL;

	return doublyList;
}

DoublyLinkedList *insert(DoublyLinkedList *doublyList, unsigned int insert_index, int value) {
	// Initialize some tracking pointers
	// Create a node pointer to the head.
	Node *currentNode = NULL;
	// Create a previous node pointer to make the switch easier.
	Node *previousNode = NULL;

	// Update the list size.
	int list_size = doublyList->size + 1;

	// Assert the insert index is within the list size.
	assert(insert_index < list_size);

	// Reallocate enough memory to support the larger doublyList.
	doublyList = realloc(doublyList, sizeof(Node)*list_size + sizeof(int));
	// Update the structure's size attribute.
	doublyList->size = list_size;

	//Kept outside of for loop to ensure 0 insert_index case is more easily handled.
	currentNode = doublyList->head;
	
	// Walk the pointers to the insert spot.
	for(unsigned int array_index = 0; array_index<=insert_index && array_index < (list_size-1); array_index++){
		if(array_index == 0){
			;
		} else {
			currentNode = currentNode->nextNode;
			previousNode = currentNode->previousNode;
		}
		printf("\n\tarray_index: %d, CurrentNode: %d", array_index, currentNode->value);
	}

	// Perform a special update if the insert_index is at the very end.
	if(insert_index == list_size - 1){
		previousNode = currentNode;
		currentNode = NULL;
		printf("\n\tCurrentNode: NULL");
	}

	// Create a new node with a pointer to the previous and current node.
	Node *newNode = createNode(value, previousNode);
	newNode->nextNode = currentNode;

	// Update doublyList's head.
	if(insert_index == 0){
		doublyList->head = newNode;
	}
	// Update the current and previous nodes's pointer's.
	if(insert_index != list_size - 1) {
		currentNode->previousNode = newNode;
	}

	if(insert_index != 0){
		previousNode->nextNode = newNode;
	}

	return doublyList;
}

void append(DoublyLinkedList *doublyList, int value) {

}

void removeByValue(void){

}

void removeByIndex(void){

}

void printDLList(DoublyLinkedList *doublyList) {
	printf("\n== Printing Doubly Linked List of size: %d ==", doublyList->size);
 
 	Node *currentNode = doublyList->head;
	Node *nextNode;

	while(currentNode != NULL){
		nextNode = currentNode->nextNode;
		printf("\n\tNode Value = %d", currentNode->value);
		currentNode = nextNode;
	}
}

void destroyDLList(DoublyLinkedList *doublyList) {
	Node *currentNode = doublyList->head;
	Node *nextNode;

	while(currentNode != NULL){
		nextNode = currentNode->nextNode;
		deleteNode(currentNode);
		currentNode = nextNode;
	}

	free(doublyList);
}