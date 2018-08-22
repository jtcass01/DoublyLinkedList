#include <stdio.h>
#include <assert.h>
#include "headers/Node.h"
#include "headers/DoublyLinkedList.h"

int main(int argc, char *argv[]) {
	Node *testNode = createNode(8, NULL);

	printNode(testNode);

	deleteNode(testNode);
}