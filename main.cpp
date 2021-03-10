#include <iostream>

#include "MinHeap.h"

using namespace std;

int main() {
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    cout << h.extractMin() << endl;
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.printHeap();
    cout << h.extractMin() << endl;
    h.printHeap();
	return 0;
}