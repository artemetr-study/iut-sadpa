#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "Stack_Node.h"
#include "Stack_Array.h"
#include "Queue_Array.h"
#include "Queue_Node.h"

using namespace std;

void sn() {
	cout << "Stack_Node\n";
	Node* sn = createStackN("im a 1");
	addToStackN(sn, "im a 2");
	addToStackN(sn, "im a 3");
	addToStackN(sn, "im a 4");
	addToStackN(sn, "im a 5");
	cout << "Upper Element Val = " << getUpperElementValueByStackN(sn) << "\n";
	cout << "Remove Upper Element\n";
	removeUpperFromStackN(sn);
	cout << "Upper Element Val = " << getUpperElementValueByStackN(sn) << "\n";
	cout << "Remove All Elements\n";
	clearStackN(sn);
	try {
		cout << "Upper Element Val = " << getUpperElementValueByStackN(sn) << "\n";
	}
	catch (...) {
		cout << "Elements Not Found\n";
	}
}

void sa() {
	cout << "Stack_Array\n";
	StackA* sn = createStackA("im a 1");
	addToStackA(sn, "im a 2");
	addToStackA(sn, "im a 3");
	addToStackA(sn, "im a 4");
	addToStackA(sn, "im a 5");
	cout << "Upper Element Val = " << getUpperElementValueByStackA(sn) << "\n";
	cout << "Remove Upper Element\n";
	removeUpperFromStackA(sn);
	cout << "Upper Element Val = " << getUpperElementValueByStackA(sn) << "\n";
	cout << "Remove All Elements\n";
	clearStackA(sn);
	try {
		cout << "Upper Element Val = " << getUpperElementValueByStackA(sn) << "\n";
	}
	catch (...) {
		cout << "Elements Not Found\n";
	}
}

void qa() {
	cout << "Queue_Array\n";
	QueueA* sn = createQueueA("im a 1");
	addToQueueA(sn, "im a 2");
	addToQueueA(sn, "im a 3");
	addToQueueA(sn, "im a 4");
	addToQueueA(sn, "im a 5");
	cout << "Size = " << sn->size << "\n";
	addToQueueA(sn, "im a 6");
	cout << "Size = " << sn->size << "\n";
	cout << "Upper Element Val = " << getFirstElementValueByQueueA(sn) << "\n";
	cout << "Remove Upper Element\n";
	removeFirstFromQueueA(sn);
	cout << "Upper Element Val = " << getFirstElementValueByQueueA(sn) << "\n";
	cout << "Remove All Elements\n";
	clearQueueA(sn);
	try {
		cout << "Upper Element Val = " << getFirstElementValueByQueueA(sn) << "\n";
	}
	catch (...) {
		cout << "Elements Not Found\n";
	}
}

void qn() {
	cout << "Queue_Node\n";
	Node* sn = createQueueN("im a 1");
	addToQueueN(sn, "im a 2");
	addToQueueN(sn, "im a 3");
	addToQueueN(sn, "im a 4");
	addToQueueN(sn, "im a 5");
	cout << "Upper Element Val = " << getFirstElementValueByQueueN(sn) << "\n";
	cout << "Remove Upper Element\n";
	removeFirstFromQueueN(sn);
	cout << "Upper Element Val = " << getFirstElementValueByQueueN(sn) << "\n";
	cout << "Remove All Elements\n";
	clearQueueN(sn);
	try {
		cout << "Upper Element Val = " << getFirstElementValueByQueueN(sn) << "\n";
	}
	catch (...) {
		cout << "Elements Not Found\n";
	}
}

void main() {
	sn();
	sa();
	qn();
	qa();

	system("pause");
}