#pragma once
#ifndef H_QueueType
#include <iostream>
#include <cassert>
#include "Q_ADT.h"

using namespace std;

template<class Type> 
class queueType : public queueADT<Type> {
public: 
	const queueType<Type>& operator=(const queueType<Type>&);

	void initializeQueue();
	bool isEmptyQueue() const;
	bool isFullQueue() const;

	Type front() const;
	Type back() const;

	void addQueue(const Type& queueElement);
	void deleteQueue();

	queueType(int queueSize = 100);
	queueType(const queueType<Type>& otherQueue);
	~queueType();

private:
	int maxQueueSize;
	int queueFront;
	int queueRear;

	Type *list;
};

template<class Type>
void queueType<Type>::initializeQueue() {
	queueFront = maxQueueSize - 1;
	queueRear = maxQueueSize - 1;
}

template<class Type>
bool queueType<Type>::isEmptyQueue() const {
	return (queueFront == queueRear);
}

template<class Type>
bool queueType<Type>::isFullQueue() const {
	return ((queueRear + 1) % maxQueueSize == queueFront);
}


template<class Type>
void queueType<Type>::addQueue(const Type& queueElement) {
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize;
		list[queueRear] = queueElement;
	}
	else {
		cout << "The queue is full and cannot accept new elements." << endl;
	}
}

template<class Type>
void queueType<Type>::deleteQueue() {
		if (!isEmptyQueue()) {
			queueFront = (queueFront + 1) % maxQueueSize;
		}
		else {
			cout << "The queue is empty so you cannot remove elements." << endl;
		}
}

template<class Type>
Type queueType<Type>::front() const {
		assert(!isEmptyQueue());
		return list[(queueFront + 1) % maxQueueSize];
	}

template<class Type>
Type queueType<Type>::back() const {
	assert(!isEmptyQueue());
	return list[queueRear ];
}

template<class Type>
queueType<Type>::queueType(int queueSize) {
	if (queueSize <= 0) {
		cout << "Queue size must be positive. Default: 100";
		maxQueueSize = 100;
	}
	else {
		maxQueueSize = queueSize;
	}

	queueFront = maxQueueSize - 1;
	queueRear = maxQueueSize - 1;
	list = new Type[maxQueueSize];
}

template<class Type>
queueType<Type>::~queueType() {
	delete list;
}

template<class Type>
const queueType<Type>& queueType<Type>::operator= (const queueType<Type>& otherQueue) {
	if(this != &otherQueue) {
		maxQueueSize = otherQueue.maxQueueSize;
		queueFront = otherQueue.queueFront;
		queueRear = otherQueue.queueRear;

		delete list;
		list = new Type[maxQueueSize];

		if (queueFront != queueRear) {
			for (int j = (queueFront + 1) % maxQueueSize; j <= maxQueueSize && j <= queueRear; j = (j + 1) % maxQueueSize)
				list[j] = otherQueue.list[j];
		}
	}
	return *this;
}

template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue) {
	maxQueueSize = otherQueue.maxQueueSize;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;

	list = new Type[maxQueueSize];

	if (queueFront != queueRear) {
		for (int j = (queueFront + 1) % maxQueueSize; j <= queueRear; j = (j + 1) % maxQueueSize)
			list[j] = otherQueue.list[j];
	}
}

#endif H_QueueType
