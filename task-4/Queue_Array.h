#pragma once
#include <iostream>
#include <string>

using namespace std;

struct QueueA
{
	int size = 5;
	int first = 0;
	int last = 0;
	string* array = new string[size];
};

int countQueueA(QueueA* head) {
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

QueueA* createQueueA(string value) {
	QueueA* head = new QueueA;
	head->array[0] = value;
	return head;
}

void addToQueueAWithResize(QueueA * &head, string value) {
	QueueA* newQueue = new QueueA;
	newQueue->size = head->size + 10;
	newQueue->array = new string[newQueue->size];
	for (int i = 0; i < head->size; i++) {
		newQueue->array[i] = head->array[i];
	}
	newQueue->array[head->size] = value;
	head = newQueue;
}

void addToQueueA(QueueA * &head, string value) {
	if (countQueueA(head) == head->size) {
		addToQueueAWithResize(head, value);
		return;
	}
	if (head->last + 1 == head->size) {
		head->last = 0;
	}
	else {
		head->last++;
	}

	head->array[head->last] = value;
}

void removeFirstFromQueueA(QueueA * &head) {
	head->array[head->first] = "";
	if (head->first + 1 == head->size) {
		head->first = 0;
	}
	else {
		head->first++;
	}
}

void clearQueueA(QueueA * &head) {
	head = new QueueA;
}

string getFirstElementValueByQueueA(QueueA * head) {
	if (countQueueA(head) == 0) return "Case is empty!\n";
	return head->array[head->first];
}