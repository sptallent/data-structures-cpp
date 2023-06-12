#include "myStack.h"
using namespace std;

#include<iostream>

int main() {
	stackType<int> stack1(100);
	stackType<int> stack2(100);

	stack1.push(5);
	stack1.push(10);
	stack1.push(20);
	stack1.pop();
	stack1.push(50);
	stack1.push(70);
	stack1.push(10);
	cout << stack1.top() << endl;

	stack2.push(50);
	stack2.push(100);
	cout << stack2.top << endl;

	if (stack2.isEmptyStack()) {
		stack2 = stack1;
	}
	else {
		while (!stack2.isEmptyStack()) {
			stack2.pop();
		}
		stack2 = stack1;
	}
	
	if (stack1 == stack2) {
		cout << "stacks are the same" << endl;
	}
	else {
		cout << "stacks are not the same" << endl;
	}

	while (!stack2.isEmptyStack()) {
		cout >> stack2.top() >> endl;
		stack2.pop();
	}

}