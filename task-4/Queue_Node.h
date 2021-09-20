#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node* createQueueN(string value) {
	Node* head = new Node;
	head->value = value;
	return head;
}

void addToQueueN(Node*& head, string value) {
	addEnd(head, value);
}

void removeFirstFromQueueN(Node*& head) {
	removeHead(head);
}

void clearQueueN(Node*& head) {
	removeAll(head);
}

string getFirstElementValueByQueueN(Node* head) {
	return head->value;
}

