/*
** File:         test.c
** Author:       Jacob Taylor Cassady
** Description:  
** Last Updated: 8/21/18
*/

/* Compiler/OS Headers */
#include <stdlib.h>
#include <stdio.h>
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

void insert(void) {

}

void append(void) {

}

void removeByValue(void){

}

void removeByIndex(void){

}

void printDLList(DoublyLinkedList *doublyList) {
	printf("== Printing Doubly Linked List of size: %d ==", doublyList->size);
 
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