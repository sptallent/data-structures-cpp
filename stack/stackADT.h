#pragma once
#ifndef H_StackADT
#define H_StackADT

template <class type>
class stackADT {
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};
#endif