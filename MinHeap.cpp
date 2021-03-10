#include "MinHeap.h"

#include <iostream>

void swap(int* v1, int* v2);

MinHeap::MinHeap(int cap) {
	capacity = cap;
	hsize = 0;//current size
	harr = new int[capacity];
}

int MinHeap::getMin() {
	if (hsize < 1) { return -1; }
	return harr[0];
}

int MinHeap::right(int i) {
	return (2 * i) + 2;
}
int MinHeap::left(int i) {
	return (2 * i) + 1;
}
int MinHeap::getParent(int i) {
	return (i-1) / 2;
}

void MinHeap::insert(int val) {
	if (hsize == capacity) {
		std::cout << "heap size is full" << std::endl;
	}
	int i = hsize;
	hsize++;
	harr[i] = val;

	//fix the order, swap with its parent until it is bigger than parent
	//i=0 has no parent
	while (i!=0 && harr[getParent(i)] > harr[i]) {
		swap(&harr[getParent(i)], &harr[i]);
	}
}

int MinHeap::extractMin() {
	if (hsize <= 0) {
		//empty heap
		return -1;
	}
	if (hsize == 1) {
		hsize--;
		return harr[0];
	}

	int root = harr[0];//min value
	harr[0] = harr[hsize - 1];//swap with the last element
	MinHeapify(0);
	hsize--;
	return root;
}

void MinHeap::MinHeapify(int i) {//keep swapping with left or right until order is fixed
	int l_i = left(i);
	int r_i = right(i);
	int smallest_i = i;
	if (l_i < hsize && harr[l_i] < harr[i]) {
		smallest_i = l_i;
	}
	if (r_i < hsize && harr[r_i] < harr[smallest_i]) {
		smallest_i = r_i;
	}
	if (smallest_i != i) {
		swap(&harr[smallest_i], &harr[i]);
		i = smallest_i;
		MinHeapify(i);
	}
}

void MinHeap::printHeap() {
	for (int i = 0; i < hsize; i++) {
		std::cout << harr[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int* v1, int* v2) {
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}