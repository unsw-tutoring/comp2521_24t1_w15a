#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int elem;
	struct node *left;
	struct node *right;
};

// returns the number of odd values in a binary search tree
int bstCountOdds(struct node *t) {
	if (t == NULL) return 0;

	return (t->elem % 2) 
			+ bstCountOdds(t->left) 
			+ bstCountOdds(t->right);
}

// count number of internal nodes in a given tree
// an internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;

	return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1
// (when a given key is not in the binary search tree)
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
	if (t == NULL) return -1;
	if (t->elem == key) return 0;

	int level = -1;

	if (t->elem < key) {
		level = bstNodeLevel(t->right, key);
	} else {
		level = bstNodeLevel(t->left, key);
	}

	if (level == -1) return -1;
	return level + 1;
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit
int bstCountGreater(struct node *t, int val) {
	if (t == NULL) return 0;

	if (t->elem <= val) {
		return bstCountGreater(t->right, val);
	}

	return ((t->elem > val) ? 1 : 0) 
			+ bstCountGreater(t->left, val) 
			+ bstCountGreater(t->right, val);
}

#define NOT_HEIGHT_BALANCED -99

// returns the height of a given binary tree if it is height - balanced,
// and NOT_HEIGHT_BALANCED otherwise.
// Height-balanced tree: We say that a basic binary tree is height-balanced if,
//      for every node, the absolute difference between the height of the left
//      subtree and the height of the right subtree is one or less. In other
//      words, every node needs to satisfy the following criteria:
//      abs(height(left) - height(right)) ≤ 1
int isHeightBalanced(struct node *t) {
	// base case: height of empty tree is -1
	if (t == NULL) return -1;

	int left = isHeightBalanced(t->left); // height of left subtree or NOT_HEIGHT_BALANCED
	int right = isHeightBalanced(t->right); // same

	// if either left or right subtrees are not height balanced
	// then the whole tree is not height balanced
	if (left == NOT_HEIGHT_BALANCED || right == NOT_HEIGHT_BALANCED) {
		return NOT_HEIGHT_BALANCED;
	}
	
	// if left and right heights differ by more than 1
	// then the tree is not height balanced
	if (abs(left - right) > 1) {
		return NOT_HEIGHT_BALANCED;
	}

	// height of tree is 1 + max(left, right)
	return 1 + ((left < right) ? right : left);
}

// challenging question!

// return the kth smallest node in the binary search tree
// return -1 if no such node exists (e.g. the 5th smallest number 
// if a tree with only 3 nodes)
int kthSmallest(struct node *t, int k) {
	// the 'global' variables that we want all recursive functions
	// to have access to
	int curr = 0;
	int ans = -1;

	// in-order traversal
	doKthSmallest(t, k, &curr, &ans);

	return ans;
}

void doKthSmallest(struct node *t, int k, int *curr, int *ans) {
	if (t == NULL) return;

	doKthSmallest(t->left, k, curr, ans);

	(*curr)++;
	if (k == *curr) {
		*ans = t->elem;
		return;
	}

	doKthSmallest(t->right, k, curr, ans);
}
