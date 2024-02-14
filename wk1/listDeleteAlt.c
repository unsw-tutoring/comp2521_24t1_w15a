#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};


// delete the first instance of node with 'value' from the linked list
void listDelete(struct list *list, int value) {
	// if linked list empty
	if (list->head == NULL) return;

	// if first node is value to delete
	if (list->head->value == value) {
		struct node *newHead = list->head->next;
		free(list->head);
		list->head = newHead;
		return;
	}

	struct node *curr = list->head;
	while (curr->next != NULL) {
		if (curr->next->value == value) {
			struct node *tmp = curr->next->next;
			free(curr->next);
			curr->next = tmp;
			break;
		}
	}
}
