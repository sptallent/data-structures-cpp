#ifndef H_StackType
#define H_StackType
#include<iostream>
#include<cassert>
#include "stackADT.h"

using namespace std;

template <class Type>
class stackType : public stackADT<Type> {
public:
	const stackType<Type>& operator =(const stackType<Type>&);
	void initializeStack();

	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	void pop();
	bool operator==(const stackType<Type>& otherStack) const;

	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();

private:
	int maxStackSize;
	int stackTop;
	Type *list;
	void copyStack(const stackType<Type>& otherStack);
};

template <class Type>
void stackType<Type>::isEmptyStack() {
	return (stackTop == 0);
}

template <class Type>
void stackType<Type>::initliazeStack() {
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isFullStack() const {
	return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem) {
	if (!isFullStack) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else {}
	cout << "The stack is full. Can't add new item.";
}

template <class Type>
Type stackType<Type>::top() const {
	if (stackTop != 0)
		return list[stackTop - 1];
	return 0;
}

template <class Type>
void stackType<Type>::pop() const {
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "Stack is empty";
}

template <class Type>
stackType<Type>::stackType(int stackSize) {
	if (stackSize <= 0) {
		maxStackSize = 100;
	}
	else {
		maxStackSize = stackSize;
	}

	stackTop = 0;
	list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType() {
	delete[] list;
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) {
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	for (int i = 0; i < stackTop; i++)
		list[i] = otherStack.list[i];
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
	list = null;
	copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack) {
	if (this != &otherStack)
		copyStack(otherStack);
	return *this;
}

template <class Type>
bool stackType<Type>::operator==(const stackType<Type>& otherStack) const {
	if (this == &otherStack)
		return true;
	else if (maxStackSize != otherStack.maxStackSize || stackTop != otherStack.stackTop)
		return false;
	else {
		for (int i = 0; i < stackTop; i++) {
			if (list[i] != otherStack.list[i])
				return false;
			return true;
		}
	}
}
#endif
