#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Node.h"


int main(int argc, char *argv[]) {
	Node *testNode = malloc(sizeof(Node));
	assert(testNode != NULL);

	testNode->value = 5;

	printf("testNode value = %d", testNode->value);

	free(testNode);

	return 0;
}