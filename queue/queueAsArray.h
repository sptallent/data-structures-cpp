//Header file QueueAsArray

#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include"queueADT.h"
#include <cassert>

using namespace std;

template<class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	// overload the assignment operator
	void initializeQueue();
	bool isEmptyQueue() const;
	bool isFullQueue() const;

	Type front() const;

	Type back() const;

	void addQueue(const Type& queueElement);

	void deleteQueue();

	queueType(int queueSize = 100);
	queueType(const queueType<Type>& otherQueue); // copy constructor
	~queueType(); //destructor

private:
	int maxQueueSize;
	int queueFront;
	int queueRear;
	Type *list;  //pointer to array that holds queue elements 
};

template<class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = maxQueueSize - 1;
	queueRear = maxQueueSize - 1;
}

template<class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (queueFront == queueRear);
}

template<class Type>
bool queueType<Type>::isFullQueue() const
{
	return ((queueRear + 1) % maxQueueSize == queueFront);
}

template<class Type>
void queueType<Type>::addQueue(const Type& queueElement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize;
		list[queueRear] = queueElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
}

template<class Type>
void queueType<Type>::deleteQueue()
{
	if (!isEmptyQueue())
		queueFront = (queueFront + 1) % maxQueueSize;
	else
		cout << "Cannot remove from an empty queue." << endl;
}

template<class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list[(queueFront + 1) % maxQueueSize];
}

template<class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[(queueRear + 1) % maxQueueSize];
}

template<class Type>
queueType<Type>::queueType(int queueSize)   //constructor
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize;  //set maxQueueSize to queueSize

	queueFront = maxQueueSize - 1;  //initialize queueFront
	queueRear = maxQueueSize - 1;   //initiaize queueRear
	list = new Type[maxQueueSize];  //create the array to
									//hold queue elements
}

template<class Type>
queueType<Type>::~queueType()   //destructor
{
	delete[] list;
}

template<class Type>
const queueType<Type>& queueType<Type>::operator=
(const queueType<Type>& otherQueue)
{
	int j;

	if (this != &otherQueue) //avoid self-copy
	{
		maxQueueSize = otherQueue.maxQueueSize;
		queueFront = otherQueue.queueFront;
		queueRear = otherQueue.queueRear;

		delete[] list;
		list = new Type[maxQueueSize];

		if (queueFront != queueRear)						//if other queue is not empty
			for (j = (queueFront + 1) % maxQueueSize; j <= queueRear;
				j = (j + 1) % maxQueueSize)  //copy other queue in this queue
				list[j] = otherQueue.list[j];
	} //end if

	return *this;
}

template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
	maxQueueSize = otherQueue.maxQueueSize;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;

	list = new Type[maxQueueSize];

	if (queueFront != queueRear)	//if other queue is not empty
		for (int j = (queueFront + 1) % maxQueueSize; j <= queueRear;
			j = (j + 1) % maxQueueSize)  //copy other queue in this queue
			list[j] = otherQueue.list[j];

}

#endif