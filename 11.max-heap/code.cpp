#include <iostream>
#include "function.h"
#include <cstring>

using namespace std;

void Implement::Insert(int value) {
    int currentNode = ++size;

    while(currentNode !=1 && heap[currentNode/2] < value) {
        // Swap with parent node
        heap[currentNode]=heap[currentNode/2];
        currentNode /= 2; // currentNode now points to parent
    }

    heap[currentNode] = value;
}

void Implement::DeleteMax() {
    // TODO
    if ( size > 0 ) {
        heap[0] = 0;
        size--;
    }
}

int Implement::MaxPathWeight(int index) {
    // TODO
    return 0;
}

string Implement::InorderTraversal(int index) {
    // TODO
    return "";
}

string Implement::PreorderTraversal(int index) {
    // TODO
    return "";
}

string Implement::PostorderTraversal(int index) {
    // TODO
    return "";
}

