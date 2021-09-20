#pragma once
#include <string>
#include <iostream>
#include "Tree.h"

using namespace std;

void main() {
	Tree* root = new Tree;
	addToTree(root, 12);
	addToTree(root, 15);
	addToTree(root, 7);
	addToTree(root, 99);
	addToTree(root, 38);
	addToTree(root, 42);
	addToTree(root, 34);
	addToTree(root, 16);
	addToTree(root, 88);
	addToTree(root, 75);
	addToTree(root, 3);
	preorderBypass(root);
	cout << endl;
	postorderBypass(root);
	cout << endl;
	inorderBypass(root);
	cout << endl;
	Tree* kus = findByValue(root, 75);
	cout << kus->father->value;
	cout << endl;
	kus = getMax(root);
	cout << kus->value;
	cout << endl;
	kus = getMin(root);
	cout << kus->value;
	cout << endl;
	deleteTree(root);
	preorderBypass(root);
	cout << endl;
	system("pause");
}