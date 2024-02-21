#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

// create a new empty list
struct node *ListNew() {
	return NULL;
}

// add item to end of list
List ListAdd(List l, int val) {
	// malloc a new node
	List newNode = malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = val;

	// if empty list
	if (l == NULL) {
		return newNode;
	}

	// add to end of list
	List curr = l;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	return l;
}

// delete the first item with value 'val' from list -- recursively
// if 'val' is not in the list, do nothing
// returns the head of the new linked list
struct node *ListDelete(struct node *l, int val) {
	if (l == NULL) return NULL;
	if (l->data == val) {
		struct node *newHead = l->next;
		free(l);
		return newHead;
	}

	// struct node *newHeadOfRestOfList = ListDelete(l->next, val);
	// l->next = newHeadOfRestOfList;
	l->next = ListDelete(l->next, val);
	return l;
}

// delete all odd numbers from list -- recursively
struct node *ListDeleteOdds(struct node *l) {
	// TODO
	return NULL;
}

// delete every second node (second, fourth, sixth, etc. node)
struct node *ListDeleteSecond(struct node *l) {
	// TODO
	return NULL;
}

// prints out the linked list
void ListPrint(struct node *l) {
	// TODO
}

// prints out the linked list in reverse
void ListPrintReverse(struct node *l) {
	// TODO
}

// returns length of linked list
int ListLength(struct node *l) {
	// TODO
	return 0;
}

// returns number of odd nodes in linked list
int ListCountOdd(struct node *l) {
	if (l == NULL) return 0;

	int numOfOddNodesInRestOfList = ListCountOdd(l->next);
	if (l->data % 2 == 1) {
		return 1 + numOfOddNodesInRestOfList;
	} else {
		return numOfOddNodesInRestOfList;
	}
}

// check if list is sorted in non-descending order
bool ListIsSorted(struct node *l) {
	if (l == NULL) return true;
	if (l->next == NULL) return true; // if only one node, list is sorted

	// we can safely assume that l != NULL and l->next != NULL
	bool restOfListIsSorted = ListIsSorted(l->next);

	// if (l->data <= l->next->data && restOfListIsSorted) return true;
	// return false;

	return (l->data <= l->next->data && restOfListIsSorted);
}

// ! THE FOLLOWING TWO EXAMPLES SHOW TWO COMMON TRICKS / TECHNIQUES YOU CAN
// ! USE WHEN CODING RECURSIVELY. TAKE NOTE OF THESE.

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransform(struct node *l) {
	// TODO
	return;
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransformAlternate(struct node *l) {
	// TODO
	return;
}
