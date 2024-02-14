#include <stdio.h>
#include <stdlib.h>

// modify this to use malloc instead of creating on the stack
struct node {
	int value;
	struct node *next;
};

// modify this to use malloc instead of creating on the stack
int main(void) {
	struct node n;
	n.value = 42;
	n.next = NULL;

	// TODO
	struct node *ptr = malloc(sizeof(struct node));
	ptr->value = 42;
	ptr->next = NULL;
}

// modify this to use malloc instead of creating on the stack
int main(void) {
	int a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}

	// TODO
	int *arr = malloc(sizeof(int) * 5); // mallocing 20 bytes
	for (int i = 0; i < 5; i++) {
		arr[i] = 42;
	}
}
