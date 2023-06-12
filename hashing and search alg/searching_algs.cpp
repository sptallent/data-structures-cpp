#include "orderedArrayListType.h"

using namespace std;

#include<stdlib.h>
#include<iostream>

int main() {
	
	orderedArrayListType<int> list(1000);
	
	while (list.getLength() < list.maxListSize()) {
		int r = (rand() % 1000) + (rand() % 1000);
		list.insertOrd(r);
	}

	list.print();
	cout << "List Length: " << list.getLength() << endl;
	
	list.binarySearch(567);
	cout << "Comparisons for binary search: " << list.noOfComparisons() << endl;
	list.initializeNoOfComparisons();
	list.binarySearch(1030);
	cout << "Comparisons for binary search: " << list.noOfComparisons() << endl;
	list.initializeNoOfComparisons();
	list.binarySearch(99);
	cout << "Comparisons for binary search: " << list.noOfComparisons() << endl;
	
	getchar();
	return 0;
}