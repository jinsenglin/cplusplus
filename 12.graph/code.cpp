#include <iostream>
#include "function.h"
#include <cstring>

#include <list>
#include <queue>
#include <stack> 

using namespace std;

void Implement::addEdge(const int label_1, const int label_2 , const int weight) {
    // TODO
}

void Implement::deleteEdge(const int label_1, const int label_2) {
    // TODO
}

void Implement::deleteVertex(const int label) {
    // TODO
}

int Implement::degree(const int label) {
    // TODO
    return 0;
}

bool Implement::isExistPath(const int label_1, const int label_2) {
    // TODO
    return false;
}

void Implement::deleteGraph() {
    // this->VertexArr; // its type is std::list<Vertex>
    // this->VertexArr.front() // its type is Vertex
    // this->VertexArr.front().label // its type is int
    // this->VertexArr.front().v_degree // its type is int
    // this->VertexArr.front().neighbors // its type is std::list<Neighbor>
    // this->VertexArr.front().neighbors.front() // its type is Neighbor
    // this->VertexArr.front().neighbors.front().label // its type is int
    // this->VertexArr.front().neighbors.front().weight // its type is int

    /*cout << "DEBUG: stack" << endl;
    stack<int> s;
    s.push(10);
    s.push(20);
    for(int i=0 ; i<s.size() ; i++){
        cout << s.top() << endl;
        s.pop();
    }

    cout << "DEBUG: queue" << endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    for(int i=0 ; i<q.size() ; i++){
        cout << q.front() << endl;
        cout << q.back() << endl;
        q.pop();
    }

    cout << "DEBUG: list" << endl;
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    for(int i=0 ; i<l.size() ; i++){
        cout << l.front() << endl;
        cout << l.back() << endl;
        l.pop_back();
    }*/

    // TODO
}

int Implement::number_of_component() {
    // TODO
    return 0;
}

bool Implement::isExistCycle() {
    // TODO
    return false;
}
