/*
** File:         test.c
** Author:       Jacob Taylor Cassady
** Description:  
** Last Updated: 8/21/18
*/

/* Compiler/OS Headers */
#include <stdio.h>
#include <assert.h>
/* User Created Headers */
#include "headers/Node.h"
#include "headers/DoublyLinkedList.h"


/* Constants */
#define TEST_LIST_SIZE 10


/* Function prototypes */
void nodeTest(void);
void doublyLinkedListTest(void);
void printArray(int *, int);


/* Main function */
int main(int argc, char *argv[]) {
	doublyLinkedListTest();
}


/* Function definitions */
void nodeTest(void) {
	Node *testNode = createNode(50, NULL);

	printNode(testNode);

	deleteNode(testNode);
}

void doublyLinkedListTest(void){
	int array_size = TEST_LIST_SIZE;
	int array[TEST_LIST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	DoublyLinkedList* testList = createFromArray(array, array_size);

	printDLList(testList);

	printf("\n\nPerforming insert...");
	testList = insert(testList, 0, 100);
	testList = insert(testList, 2, 15);
	testList = insert(testList, 12, 20);
	printDLList(testList);

	destroyDLList(testList);
}

void printArray(int *array, int array_size){
	printf("== Printing Array of size: %d ==", array_size);

	for(unsigned int array_index = 0; array_index < array_size; array_index++){
		printf("\n\tArray[%d] = %d", array_index, *(array + array_index));
	}
}
