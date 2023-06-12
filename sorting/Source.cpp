using namespace std;

#include<iostream>
#include<ctime>
#include "arrayListType.h"

int main() {
	arrayListType<int> l1(100);

	srand((unsigned)time(NULL));
	while (!l1.isFull()) {
		l1.insert(rand());
	}

	l1.print();
	l1.quickSort();
	cout << endl <<  "quick sorted" << endl << endl;;
	l1.print();

	getchar();
}