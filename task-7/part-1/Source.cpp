#include <iostream>
#include "RecursiveFunctionsLibrary.h"
#include <string.h>

using namespace std;

void delimiterString() {
	cout << "========================================================\n";
}

void ender() {
	string ender_string;
	do {
		cout << "Input \"stop\" to stop the program: ";
		cin >> ender_string;
	} while (ender_string != (string)"stop");
}

void factorialOfNumberMain() {
	int a;

	cout << "Input integer for calculate it factorial: ";
	cin >> a;
	cout << "Factorial of integer: " << factorialOfNumber(a) << "\n";
}

void naturalPowerOfNumberMain() {
	int power_of;
	float number;

	cout << "Input any number and it power for calculate power of current number: ";
	cin >> number >> power_of;
	cout << "Power of current number: " << naturalPowerOfNumber(power_of, number) << "\n";
}

void nMemberOfArithmeticProgressionMain() {
	float first_member;
	float difference;
	int n;

	cout << "Input:\n * first member;\n * difference;\n * number of needed member of arithmetic progresstion;\nfor calculate needed member of arithmetic progresstion: ";
	cin >> first_member >> difference >> n;
	cout << "Needed member of arithmetic progresstion: " << nMemberOfArithmeticProgression(first_member, difference, n) << "\n";
}

void nMemberOfGeometricProgressionMain() {
	float first_member;
	float denominator;
	int n;

	cout << "Input:\n * first member;\n * denominator;\n * number of needed member of geometric progresstion;\nfor calculate needed member of geometric progresstion: ";
	cin >> first_member >> denominator >> n;
	cout << "Needed member of geometric progresstion: " << nMemberOfGeometricProgression(first_member, denominator, n) << "\n";
}

void sumOfMemberOfArithmeticProgressionMain() {
	float first_member;
	float difference;
	int n;

	cout << "Input:\n * first member;\n * difference;\n * number of needed member of arithmetic progresstion;\nfor calculate sum of members of arithmetic progresstion: ";
	cin >> first_member >> difference >> n;
	cout << "Sum of members of arithmetic progresstion: " << sumOfMemberOfArithmeticProgression(first_member, difference, n) << "\n";
}

void sumOfMemberOfGeometricProgressionMain() {
	float first_member;
	float denominator;
	int n;

	cout << "Input:\n * first member;\n * denominator;\n * number of needed member of geometric progresstion;\nfor calculate sum of members of geometric progresstion: ";
	cin >> first_member >> denominator >> n;
	cout << "Sum of members of geometric progresstion: " << sumOfMemberOfGeometricProgression(first_member, denominator, n) << "\n";
}

void nFibonacciNumberMain() {
	int n;

	cout << "Input N number of member of Fibonaccis sequence: ";
	cin >> n;
	cout << "N member of Fibonaccis sequence: " << nFibonacciNumber(n) << "\n";
}

void getMinimumValueAndIndexFromArray() {
	int* array = new int[10];
	for (int i = 0; i < 10; i++) {
		array[i] = rand() % 51;
	}

	cout << "Searching minimum value and index element form random array: \n";
	for (int i = 0; i < 10; i++) {
		array[i] = rand() % 51;
		cout << array[i] << "\t";
	}
	cout << "\nIndex of minimum element of array: " << getMinimumIndexFromArray(array, 10) << "\n";
	cout << "Value of minimum element of array: " << getMinimumValueFromArray(array, 10) << "\n";
}

void main() {
	delimiterString();
	factorialOfNumberMain();

	delimiterString();
	naturalPowerOfNumberMain();

	delimiterString();
	nMemberOfArithmeticProgressionMain();

	delimiterString();
	nMemberOfGeometricProgressionMain();

	delimiterString();
	sumOfMemberOfArithmeticProgressionMain();

	delimiterString();
	sumOfMemberOfGeometricProgressionMain();

	delimiterString();
	nFibonacciNumberMain();

	delimiterString();
	getMinimumValueAndIndexFromArray();

	delimiterString();
	ender();
}