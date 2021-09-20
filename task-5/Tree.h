#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Tree
{
	int value;
	Tree* father = NULL;
	Tree* left_child = NULL;
	Tree* right_sibling = NULL;
};

bool isEmpty(Tree* tree) {
	return !tree || tree->value == -842150451;
}

void preorderBypass(Tree* tree) {
	if (isEmpty(tree)) return;
	printf(" % i", tree->value);
	preorderBypass(tree->left_child);
	preorderBypass(tree->right_sibling);
}

void postorderBypass(Tree* tree) {
	if (isEmpty(tree)) return;
	postorderBypass(tree->left_child);
	postorderBypass(tree->right_sibling);
	printf(" % i", tree->value);
}

void inorderBypass(Tree* tree) {
	if (isEmpty(tree)) return;
	inorderBypass(tree->left_child);
	printf(" % i", tree->value);
	inorderBypass(tree->right_sibling);
}

void addToTree(Tree*& tree, int value) {
	if (isEmpty(tree)) {
		tree = new Tree;
		tree->value = value;
		return;
	}
	Tree* n_node = new Tree;
	n_node->value = value;
	Tree* current_tree = tree;
	while (true) {
		if (current_tree->value > value) {
			if (!current_tree->left_child) {
				current_tree->left_child = n_node;
				n_node->father = current_tree;
				break;
			}
			else {
				current_tree = current_tree->left_child;
				continue;
			}
		}
		else {
			if (!current_tree->right_sibling) {
				current_tree->right_sibling = n_node;
				n_node->father = current_tree;
				break;
			}
			else {
				current_tree = current_tree->right_sibling;
				continue;
			}
		}
	}
}

void deleteTree(Tree*& tree) {
	if (isEmpty(tree)) {
		return;
	}
	deleteTree(tree->left_child);
	deleteTree(tree->right_sibling);
	tree = NULL;
}

Tree* findByValue(Tree* tree, int value) {
	if (isEmpty(tree)) return NULL;
	Tree* current_tree = tree;
	while (true) {
		if (current_tree->value > value) {
			if (!current_tree->left_child) {
				return NULL;
			}
			else {
				current_tree = current_tree->left_child;
				continue;
			}
		} else if (current_tree->value < value) {
			if (!current_tree->right_sibling) {
				return NULL;
			}
			else {
				current_tree = current_tree->right_sibling;
				continue;
			}
		}
		else {
			return current_tree;
		}
	}
}

Tree* getMin(Tree* tree) {
	while (tree->left_child != NULL) {
		tree = tree->left_child;
	}
	return tree;
}

Tree* getMax(Tree* tree) {
	
		while (tree->right_sibling != NULL) {
			tree = tree->right_sibling;
		}

	return tree;
}