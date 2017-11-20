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
    int result = 0;

    if (index <= size) {
        int leftNode = index*2;
        int rightNode = index*2+1;

        int leftWeight = MaxPathWeight(leftNode);
        int rightWeight = MaxPathWeight(rightNode);

        if (leftWeight > rightWeight) {
            result = leftWeight + heap[index];
        }
        else {
            result = rightWeight + heap[index];
        }
    }

    return result;
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
    string result = "";

    if (index <= size) {
        int leftNode = index*2;
        int rightNode = index*2+1;

        //cout << "DEBUG: " << to_string(heap[index]) << endl;
        result.append(to_string(heap[index]));

        string leftResult = PreorderTraversal(leftNode);
        if (leftResult != "") {
            //cout << "DEBUG: leftResult = '" << leftResult << "'" << endl;
            result.append(" " + leftResult);
        }

        string rightResult = PreorderTraversal(rightNode);
        if (rightResult != "") {
            //cout << "DEBUG: rightResult = '" << rightResult << "'" << endl;
            result.append(" " + rightResult);
        }
    }

    return result;
}

string Implement::PostorderTraversal(int index) {
    string result = "";

    if (index <= size) {
        int leftNode = index*2;
        int rightNode = index*2+1;

        string leftResult = PostorderTraversal(leftNode);
        if (leftResult != "") {
            //cout << "DEBUG: leftResult = '" << leftResult << "'" << endl;
            result.append(leftResult);
        }

        string rightResult = PostorderTraversal(rightNode);
        if (rightResult != "") {
            //cout << "DEBUG: rightResult = '" << rightResult << "'" << endl;
            result.append(" " + rightResult);
        }

        //cout << "DEBUG: " << to_string(heap[index]) << endl;
        if (result != "") {
            result.append(" " + to_string(heap[index]));
        }
        else {
            result.append(to_string(heap[index]));
        }
    }

    return result;
}

