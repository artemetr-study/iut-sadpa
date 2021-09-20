#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
public:
	string value;
	Node* next = NULL;
	Node* back = NULL;
};

bool isEmpty(Node* head) {
	try {
		if (head == NULL)
			return true;
		string new_st = head->value;
		return false;
	}
	catch (...) {
		return true;
	}
}

bool isCircle(Node * head) {
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
		if (current == head)
			return true;
	}
	return false;
}

void addHead(Node * &head, string value) {
	if (isEmpty(head))
		return;

	if (isCircle(head))
		throw ("Illegal operation: addHead!");

	Node* temp = new Node;

	temp->next = head;
	temp->value = value;
	head->back = temp;

	head = temp;
}

void removeHead(Node * &head) {
	if (isEmpty(head))
		return;

	if (isCircle(head))
		throw ("Illegal operation: removeHead!");

	Node* temp = head->next;
	temp->back = NULL;

	delete(head);

	head = temp;
}

void remove(Node * &head, Node * needed) {
	if (isEmpty(head) || isEmpty(needed))
		return;

	Node * current = head;
	Node * pre_current = head;
	while (current != needed) {
		if (isEmpty(current->next))
			return;
		pre_current = current;
		current = current->next;
	}

	if (isEmpty(current->next)) {
		current->back->next = NULL;
		delete(current);
		return;
	}

	if (pre_current == current) {
		current->next->back = NULL;
		head = current->next;
		delete(current);
		return;
	}

	current->next->back = pre_current;
	pre_current->next = current->next;
	delete(current);
}

Node* findNodeByValue(Node * head, string needed) {
	if (isEmpty(head))
		return NULL;

	Node* current = head;
	while (current->value != needed) {
		if (isEmpty(current->next))
			return NULL;
		current = current->next;
		if (current == head)
			return NULL;
	}

	return current;
}

void removeByValue(Node * &head, string value) {
	Node* needed = findNodeByValue(head, value);
	if (isEmpty(needed))
		return;

	remove(head, needed);
}

Node* getEnd(Node * head) {
	if (isEmpty(head))
		return NULL;

	if (isCircle(head))
		throw ("Illegal operation: getEnd!");

	Node* current = head;
	while (current->next != NULL)
		current = current->next;

	return current;
}

void removeEnd(Node*& head, Node* needed) {
	if (isEmpty(head))
		return;

	if (isCircle(head))
		throw ("Illegal operation: getEnd!");

	Node* end = getEnd(head);
	Node* pre_end = end->back;
	pre_end->next = NULL;
	delete(end);
}

void printNodeForward(Node * head) {
	if (isEmpty(head))
		return;

	if (isCircle(head)) {
		Node* current = head;

		cout << "--------Circle--------" << endl;
		cout << current->value << endl;
		current = current->next;
		while (current != head) {
			cout << current->value << endl;
			current = current->next;
		}
		cout << "--------END--------" << endl;
		return;
	}

	Node* current = head;

	cout << "--------List--------" << endl;
	while (!isEmpty(current)) {
		cout << current->value << endl;
		current = current->next;
	}
	cout << "--------END--------" << endl;
}

void printNodeBackward(Node * head) {
	if (isEmpty(head))
		return;

	if (isCircle(head)) {
		Node* current = head->back;

		cout << "--------Circle--------" << endl;
		cout << current->value << endl;
		current = current->back;
		while (current != head->back) {
			cout << current->value << endl;
			current = current->back;
		}
		cout << "--------END--------" << endl;
		return;
	}

	Node* current = getEnd(head);

	cout << "--------List--------" << endl;
	while (!isEmpty(current)) {
		cout << current->value << endl;
		current = current->back;
	}
	cout << "--------END--------" << endl;
}

void insertAfterItem(Node * item, string value) {
	if (isEmpty(item))
		return;

	Node* temp = new Node;
	temp->value = value;
	temp->next = item->next;
	temp->back = item;
	item->next->back = temp;
	item->next = temp;
}

Node* findNodeByIndex(Node * head, int index) {
	if (isEmpty(head) || index < 0)
		return NULL;

	Node * current = head;
	for (int i = 0; i < index; i++) {
		if (isEmpty(current->next))
			return NULL;
		current = current->next;
	}

	return current;
}

string getNodeValueByIndex(Node * head, int index) {
	if (isEmpty(head) || index < 0)
		return NULL;

	Node * current = head;
	for (int i = 0; i < index; i++) {
		if (isEmpty(current->next))
			return NULL;
		current = current->next;
	}

	return current->value;
}

void addEnd(Node * head, string value) {
	if (isEmpty(head))
		return;

	if (isCircle(head))
		throw ("Illegal operation: addEnd!");

	Node* current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = new Node;
	current->next->value = value;
	current->next->back = current;
}

void initCircle(Node * &head) {
	if (isEmpty(head))
		return;

	if (isCircle(head))
		throw ("Illegal operation: initCircle!");

	Node* current = getEnd(head);
	head->back = current;
	current->next = head;
}

void destructCircle(Node * &head) {
	if (isEmpty(head))
		return;

	if (!isCircle(head))
		throw ("Illegal operation: destructCircle!");

	head->back->next = NULL;
	head->back = NULL;
}

void removeAll(Node * &head) {
	if (isEmpty(head))
		return;

	if (isCircle(head)) {
		Node* current = head->next;
		Node* pre_current;
		while (current->next != NULL || current != head) {
			pre_current = current;
			current = current->next;
			delete(pre_current);
		}
		delete(head);
	}

	Node* current = head;
	Node* pre_current;
	while (current->next != NULL) {
		pre_current = current;
		current = current->next;
		delete(pre_current);
	}
}

void insertByIndex(Node * head, int index, Node * &new_node) {
	Node* current = findNodeByIndex(head, index - 1);
	if (current == NULL)
		return;

	new_node->next = current->next;
	new_node->back = current;
	current->next = new_node;
}

Node * merge(Node * firstNode, Node * secondNode) {
	if (isEmpty(firstNode) || isEmpty(secondNode))
		return NULL;
	if (isEmpty(firstNode))
		return secondNode;
	if (isEmpty(secondNode))
		return firstNode;
	if (isCircle(firstNode) || isCircle(secondNode))
		throw ("Illegal operation: merge!");

	Node * newNode = firstNode;
	Node * currentFirst = firstNode;
	while (currentFirst->next != NULL) {
		removeByValue(secondNode, currentFirst->value);
		currentFirst = currentFirst->next;
	}
	currentFirst->next = secondNode;

	currentFirst = newNode;
	while (currentFirst->next != NULL) {
		currentFirst->next->back = currentFirst;
		currentFirst = currentFirst->next;
	}

	return newNode;
}