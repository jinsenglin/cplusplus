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
    string result = "";

    if (index <= size) {
        int leftNode = index*2;
        int rightNode = index*2+1;

        string leftResult = InorderTraversal(leftNode);
        if (leftResult != "") {
            //cout << "DEBUG: leftResult = '" << leftResult << "'" << endl;
            result.append(leftResult);
        }

        //cout << "DEBUG: " << to_string(heap[index]) << endl;
        if (result != "") {
            result.append(" " + to_string(heap[index]));
        }
        else {
            result.append(to_string(heap[index]));
        }

        string rightResult = InorderTraversal(rightNode);
        if (rightResult != "") {
            //cout << "DEBUG: rightResult = '" << rightResult << "'" << endl;
            result.append(" " + rightResult);
        }
    }

    return result;
}

string Implement::PreorderTraversal(int index) {
    // TODO
    return "";
}

string Implement::PostorderTraversal(int index) {
    // TODO
    return "";
}

