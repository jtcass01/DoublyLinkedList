#ifndef NODE
#define NODE

typedef struct NodeT {
	int value;
	struct NodeT *nextNode;
	struct NodeT *previousNode;
} Node;

Node* createNode(int, Node *);

void printNode(Node *);

void deleteNode(Node *);

#endif