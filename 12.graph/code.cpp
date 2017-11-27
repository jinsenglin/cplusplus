#include <iostream>
#include "function.h"
#include <cstring>

#include <list>
#include <queue>
#include <stack> 

using namespace std;

void Implement::addEdge(const int label_1, const int label_2 , const int weight) {
    // add one vertex of lable == label_1 if it does not exist
    bool existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_1 ) {
            cout << "DEBUG: " << label_1 << " found" << endl;
            existed = true;
            break;
        }
    }
    if (!existed) {
        Vertex v1 (label_1); 
        this->VertexArr.push_back(v1);
        cout << "DEBUG: " << label_1 << " added" << endl;
    }

    // add one vertex of lable == label_2 if it does not existe
    existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_2 ) {
            cout << "DEBUG: " << label_2 << " found" << endl;
            existed = true;
            break;
        }
    }
    if (!existed) {
        Vertex v2 (label_2); 
        this->VertexArr.push_back(v2);
        cout << "DEBUG: " << label_2 << " added" << endl;
    }

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

    // begin: Return iterator to beginning
    // end: Return iterator to end
    // erase/remove: Delete elements
    // push_back: Add element at the end
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
