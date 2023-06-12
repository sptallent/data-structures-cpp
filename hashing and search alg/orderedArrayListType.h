#ifndef H_orderedArrayListType
#define H_orderedArrayListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType {
public:
	void insertOrd(const elemType&);
	
	int binarySearch(const elemType& item);

	int binSearchEx(const elemType& item);

	int binSeqSearch15(const elemType& item);

	orderedArrayListType(int size = 100);

	int seqSearch15(const elemType& item, int first, int last);

	int noOfComparisons() const;
	void initializeNoOfComparisons();
	void print() const;
	void insert(const elemType& insertItem);
	int seqSearch(const elemType& item) const;
	int getLength();
	int maxListSize() const;

	void insertAt(int location, const elemType& insertItem);

private:
	int comparisons;
	elemType *list;  //array to hold the list elements
	int length;      //to store the length of the list
	int maxSize;
};

template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    if (length == 0)   //the list is empty
    {
        list[0] = item;
        length++;
    }
    else if (length == maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (list[mid] == item)
                found = true;
            else if (list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while

        if (found)
            cerr << "The insert item is already in the list. "
                 << "Duplicates are not allowed." << endl;
        else
        {
            if (list[mid] < item)
                mid++;

            insertAt(mid, item);
        }
    }
}//end insertOrd

template<class elemType> int orderedArrayListType<elemType>::binarySearch
                                           (const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
		comparisons++;
        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found) 
        return mid;
	return -1;
}//end binarySearch

template<class elemType>
int orderedArrayListType<elemType>::binSearchEx(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		comparisons++;

		if (list[mid] == item)
			found = true;
		else
		{
			comparisons++;

			if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	if (found)
		return mid;
	else 
		return -1;
}

template<class elemType>
int orderedArrayListType<elemType>::binSeqSearch15(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	while (last - first > 15 && !found)
	{
		mid = (first + last) / 2;

		comparisons++;

		if (list[mid] == item)
			found = true;
		else
		{
			comparisons++;

			if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	if (found)
		return mid;
	else
		return seqSearch15(item,first,last);
}


template<class elemType>
int orderedArrayListType<elemType>::seqSearch15(const elemType& item,
												int first, int last)
{
	bool found = false;
    int loc;

	for (loc = first; loc <= last; loc++)
	{
		comparisons++;

		if (list[loc] >= item)
		{
			found = true;
			break;
		}
	}

	if (found)
		if (list[loc] == item)
		{
			comparisons++;
			return loc;
		}
		else
			return -1;
	else
		return -1;
}

template<class elemType>
int orderedArrayListType<elemType>::noOfComparisons() const
{
	return comparisons;
}

template<class elemType>
void orderedArrayListType<elemType>::initializeNoOfComparisons()
{
	comparisons = 0;
}


template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;

		maxSize = 100;
	}
	else
		maxSize = size;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
void orderedArrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";

	cout << endl;
}

template <class elemType>
void orderedArrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;

	if (length == 0)   //list is empty
		list[length++] = insertItem;    //insert the item and 
										//increment the length
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		loc = seqSearch(insertItem);

		if (loc == -1)    //the item to be inserted 
						  //does not exist in the list
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list. No duplicates are allowed." << endl;
	}
} //end insert

template <class elemType>
int orderedArrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template<class elemType>

int orderedArrayListType<elemType>::getLength() {
	return length;
}

template <class elemType>
int orderedArrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void orderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "
		<< "is out of range" << endl;
	else if (length >= maxSize)  //list is full
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		for (int i = length; i > location; i--)
			list[i] = list[i - 1];   //move the elements down

		list[location] = insertItem;  //insert the item at the 
									  //specified position

		length++;     //increment the length
	}
} //end insertAt

#endif