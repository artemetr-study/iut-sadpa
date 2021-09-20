#pragma once
#include <iostream>
#include <string>

using namespace std;

struct StackA
{
	int size = 5;
	int first = 0;
	int last = 0;
	string* array = new string[size];
};

int countStackA(StackA* head) {
	int count = 0;
	if (head->first < head->last) {
		return head->last + 1 - head->first;
	}
	if (head->last < head->first) {
		return head->last + 1 + (head->size - head->first);
	}
	if (head->last == head->first) {
		return 1;
	}
}

StackA* createStackA(string value) {
	StackA* head = new StackA;
	head->array[0] = value;
	return head;
}

void addToStackAWithResize(StackA*& head, string value) {
	StackA* newStack = new StackA;
	newStack->size = head->size + 10;
	newStack->array = new string[newStack->size];
	newStack->array[0] = value;
	for (int i = 1; i < head->size + 1; i++) {
		newStack->array[i] = head->array[i - 1];
	}
	head = newStack;
}

void addToStackA(StackA*& head, string value) {
	if (countStackA(head) == head->size) {
		addToStackAWithResize(head, value);
		return;
	}
	if (head->first - 1 >= 0) {
		head->first--;
	}
	else {
		head->first = head->size - 1;
	}

	head->array[head->first] = value;
}

void removeUpperFromStackA(StackA*& head) {
	head->array[head->first] = "";
	if (head->first + 1 == head->size) {
		head->first = 0;
	}
	else {
		head->first++;
	}
}

void clearStackA(StackA*& head) {
	head = new StackA;
}

string getUpperElementValueByStackA(StackA* head) {
	if (countStackA(head) == 0) return "Case is empty!\n";
	return head->array[head->first];
}