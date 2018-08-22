/*
** File:         test.c
** Author:       Jacob Taylor Cassady
** Description:  
** Last Updated: 8/22/18
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
	//Build a testNode.
	Node *testNode = createNode(50, NULL);
	printNode(testNode);

	//Destroy a testNode.
	deleteNode(testNode);
}

void doublyLinkedListTest(void){
	printf("\n==== Performing test of DoublyLinkedList ====\n");

	// Initialize an array to build the testList off of
	int array_size = TEST_LIST_SIZE;
	int array[TEST_LIST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Build a testList
	printf("\n\nInitial List");
	DoublyLinkedList* testList = dll_createFromArray(array, array_size);
	dll_print(testList);

	// Test boundary and nominal case of insert.
	printf("\n\nPerforming inserts... (0, 100) (2,15) (TEST_LIST_SIZE + 2, 20)");
	testList = dll_insert(testList, 0, 100);
	testList = dll_insert(testList, 2, 15);
	testList = dll_insert(testList, TEST_LIST_SIZE + 2, 20);
	dll_print(testList);

	// Test append.
	printf("\n\nPerforming append... (99)");
	testList = dll_append(testList, 99);
	dll_print(testList);

	// Test removal
	printf("\n\nPerforming removals... (value 100) (value 99) (index TEST_LIST_SIZE)");
	testList = dll_removeByValue(testList, 100);
	testList = dll_removeByValue(testList, 99);
	testList = dll_removeByValue(testList, 1000);
	testList = dll_removeByIndex(testList, 0);
	testList = dll_removeByIndex(testList, 5);
	testList = dll_removeByIndex(testList, TEST_LIST_SIZE-1);
	dll_print(testList);

	// Destroy the test list
	dll_destroy(testList);

	printf("\n\n==== testList Successfully deleted. ====\n");
}

void printArray(int *array, int array_size){
	printf("\n== Printing Array of size: %d | memory address: %p ==", array_size, array);

	for(unsigned int array_index = 0; array_index < array_size; array_index++){
		printf("\n\tArray[%d] = %d", array_index, *(array + array_index));
	}
}
