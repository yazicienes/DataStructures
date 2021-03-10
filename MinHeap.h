#pragma once

/*
Min heap using array 
parent node access by
left node access by
right node access by
priority queue
insert, remove min at O(logn)
get minimum at O(1)
*/
class MinHeap
{
	int* harr;
	int capacity;
	int hsize;
public:
	MinHeap(int cap);
	void MinHeapify(int);
	int getParent(int i);
	int left(int i);
	int right(int i);
	int extractMin();
	int getMin();
	int delVal(int i);
	void insert(int val);
	void printHeap();
};

