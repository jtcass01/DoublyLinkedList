/*
** File:         Node.c
** Author:       Jacob Taylor Cassady
** Description: 
** Last Updated: 8/22/18
*/

/* Compiler/OS Headers */
#include <stdlib.h>
#include <stdio.h>
/* User Created Headers */
#include "../headers/Node.h"

Node *createNode(int value, Node *previousNode){
	Node *newNode = malloc(sizeof(Node));

	newNode->value = value;
	newNode->previousNode = previousNode;

	return newNode;
}

void printNode(Node *node){
	printf("Node value = %d", node->value);
}

void deleteNode(Node *node){
	free(node);
}