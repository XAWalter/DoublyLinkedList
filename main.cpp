#include <iostream>

#include "IntList.h"

using namespace std;

int main() {
	const int SIZE = 10;

	//constructor
	IntList a;

	//is empty
	if (a.empty()) {
		cout << "Empty" << endl;
	}
	else {
		cout << "Not Empty" << endl;
	}

	//push back
	for (int i = 0; i < SIZE; i++) {
		a.push_back(i);
	}

	//push front
	for (int i = 0; i < SIZE; i++) {
		a.push_front(i + SIZE);
	}

	//pop back
	a.pop_back();

	//operator overload
	cout << "List: " << a << endl;

	//pop front
	a.pop_front();

	//backward list
	cout << "List Backward: ";
	a.printReverse();
	cout << endl;

	//is empty
	if (a.empty()) {
		cout << "Empty" << endl;
	}
	else {
		cout << "Not Empty" << endl;
	}

	system("pause");
	return 0;

}