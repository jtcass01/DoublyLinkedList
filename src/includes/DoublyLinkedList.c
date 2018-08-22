/*
** File:         test.c
** Author:       Jacob Taylor Cassady
** Description:  
** Last Updated: 8/22/18
*/

/* Compiler/OS Headers */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/* User Created Headers */
#include "../headers/DoublyLinkedList.h"
#include "../headers/Node.h"

#define DEBUG 0

DoublyLinkedList *dll_createFromArray(int *array, int array_size){
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

DoublyLinkedList *dll_insert(DoublyLinkedList *doublyList, unsigned int insert_index, int value) {
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
		if(DEBUG){
			printf("\n\tarray_index: %d, CurrentNode: %d", array_index, currentNode->value);
		}
	}

	// Perform a special update if the insert_index is at the very end.
	if(insert_index == list_size - 1){
		previousNode = currentNode;
		currentNode = NULL;
		if(DEBUG){
			printf("\n\tCurrentNode: NULL");
		}
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

DoublyLinkedList *dll_append(DoublyLinkedList *doublyList, int value) {
	// Create a pointer to the head.
	Node *currentNode = doublyList->head;

	// Update the list size.
	int list_size = doublyList->size + 1;

	// Reallocate enough memory to support the larger doublyList.
	doublyList = realloc(doublyList, sizeof(Node)*list_size + sizeof(int));
	// Update the structure's size attribute.
	doublyList->size = list_size;

	// Loop to the last node.
	while(currentNode->nextNode != NULL){
		currentNode = currentNode->nextNode;

		if(DEBUG) {
			printf("\n\tCurrentNode: %d", currentNode->value);
		}
	}

	// Create the new node with the last node as the previous node.
	Node *newNode = createNode(value, currentNode);

	if(DEBUG) {
		printf("\n\tnewNode: %d", newNode->value);
	}
	// Update the lastNode's nextNode
	currentNode->nextNode = newNode;

	// Return
	return doublyList;
}

DoublyLinkedList *dll_removeByValue(DoublyLinkedList *doublyList, int value) {
	int list_size;
	int found = 0;

	Node *left_of_current = NULL;
	Node *right_of_current = NULL;
	Node *currentNode = doublyList->head;

	if(currentNode->value == value) {
		found = 1;

		if(DEBUG) {
			printf("\n\tCurrentNode has a value of: %d", currentNode->value);
		}
	} else {
		while(currentNode->nextNode != NULL) {
			if(DEBUG) {
				printf("\n\tCurrentNode has a value of: %d", currentNode->value);
			}

			currentNode = currentNode->nextNode;

			if(currentNode->value == value) {
				if(DEBUG) {
					printf("\n\tNode found with value of: %d", value);
				}
				
				found = 1;
				break;
			}
		}
	}

	// if found, remove node.
	if(found){
		// Fix the nodes that used to point to the current node.
		if(currentNode->previousNode != NULL) {
			left_of_current = currentNode->previousNode;
		} else {
			doublyList->head = currentNode->nextNode;
		}

		if(currentNode->nextNode != NULL){
			right_of_current = currentNode->nextNode;
			right_of_current->previousNode = left_of_current;
		}

		if(left_of_current != NULL){
			left_of_current->nextNode = right_of_current;
		}

		// Delete the current Node.
		deleteNode(currentNode);

		// Reduce the list size by 1
		doublyList->size = doublyList->size - 1;
		// Reallocate enough memory to support the smaller doublyList.
		doublyList = realloc(doublyList, sizeof(Node)*doublyList->size + sizeof(int));
	} else {
		printf("\n\tNode containing value: %d was not found.", value);
	}

	return doublyList;
}

DoublyLinkedList *dll_removeByIndex(DoublyLinkedList *doublyList, int remove_index){
	assert(remove_index < doublyList->size);

	Node *currentNode = doublyList->head;
	Node *previousNode = NULL;
	Node *nextNode = NULL;

	if(remove_index == 0){
		;
	} else {
		for(unsigned int counter = 0; counter < remove_index; counter++){
			currentNode = currentNode->nextNode;
		}
	}

	// Fix the nodes that used to point to the current node.
	if(remove_index == 0){
		nextNode = currentNode->nextNode;
		nextNode->previousNode = NULL;
		doublyList->head = nextNode;
	} else if (remove_index == doublyList->size - 1){
		previousNode = currentNode->previousNode;
		previousNode->nextNode = NULL;
	} else {
		previousNode = currentNode->previousNode;
		nextNode = currentNode->nextNode;

		previousNode->nextNode = nextNode;
		nextNode->previousNode = previousNode;
	}

	deleteNode(currentNode);

	// Reduce the list size by 1
	doublyList->size = doublyList->size - 1;
	// Reallocate enough memory to support the smaller doublyList.
	doublyList = realloc(doublyList, sizeof(Node)*doublyList->size + sizeof(int));

	return doublyList;
}

void dll_print(DoublyLinkedList *doublyList) {
	printf("\n== Printing Doubly Linked List of size: %d | memory address: %p ====", doublyList->size, doublyList->head);
 
 	Node *currentNode = doublyList->head;
	Node *nextNode;

	while(currentNode != NULL){
		nextNode = currentNode->nextNode;
		printf("\n\tNode Value = %d", currentNode->value);
		currentNode = nextNode;
	}
}

void dll_destroy(DoublyLinkedList *doublyList) {
	Node *currentNode = doublyList->head;
	Node *nextNode;

	while(currentNode != NULL){
		nextNode = currentNode->nextNode;
		deleteNode(currentNode);
		currentNode = nextNode;
	}

	free(doublyList);
}