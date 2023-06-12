#include "binarySearchTree.h"
using namespace std;
#include<iostream>
int main() {
	bSearchTreeType<int> tree1;
	int num;
	cout << "Enter a value: ";
	cin >> num;

	while (num != -999) {
		tree1.insert(num);
		cout << "Enter a value: ";
		cin >> num;
 	}

	tree1.preorderTraversal();
}

