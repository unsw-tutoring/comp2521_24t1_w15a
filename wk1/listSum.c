#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

// return the sum of nodes in a linked list, given its head
// ! use a while loop
int listSum(struct node *list) {
	int total = 0;
	struct node *curr = list;
	while (curr != NULL) {
		total += curr->value;
		curr = curr->next;
	}

	return total;
}

// return the sum of nodes in a linked list, given its head
// ! use a for loop
int listSum(struct node *list) {
	int total = 0;
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		total += curr->value;
	}
	return 0;
}
