#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node* createStackN(string value) {
	Node* head = new Node;
	head->value = value;
	return head;
}

void addToStackN(Node*& head, string value) {
	addHead(head, value);
}

void removeUpperFromStackN(Node*& head) {
	removeHead(head);
}

void clearStackN(Node*& head) {
	removeAll(head);
}

string getUpperElementValueByStackN(Node* head) {
	return head->value;
}

