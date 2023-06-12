#include "H_QueueType.h"

using namespace std;

#include<iostream>

int main() {

	queueType<int> q1(100);
	queueType<int> q2(100);

	q1.addQueue(5);
	q1.addQueue(10);
	q1.addQueue(8);


	cout << "Q1 Front: " << q1.front() << " Back: " << q1.back() << endl;
	if (!q1.isEmptyQueue()) {
		q1.deleteQueue();
	}

	int count = 1;
	while (!q1.isFullQueue()) {
		q1.addQueue(count);
		count++;
	}

	//q2 = q1;

	cout << "Q1 Front: " << q1.front() << " Back: " << q1.back() << endl;
	//cout << "Q2 Front: " << q2.front() << " Back: " << q2.back() << endl;

	queueType<int> q3(q1);
	cout << "Q3 Front: " << q3.front() << " Back: " << q3.back() << endl;

	return 0;
}