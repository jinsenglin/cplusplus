#include <iostream>
#include "function.h"
#include <cstring>

#include <list>
#include <queue>
#include <stack> 

using namespace std;

void Implement::addEdge(const int label_1, const int label_2 , const int weight) {
    // add one vertex of lable == label_1 if it does not exist
    bool vertex_existed = false;
    bool neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_1 ) {
            //cout << "DEBUG: vertex " << label_1 << " found" << endl;
            vertex_existed = true;

            // update or add its neighbor
            for (list<Neighbor>::iterator it2=(*it).neighbors.begin(); it2 != (*it).neighbors.end(); ++it2) {
                if ( (*it2).label == label_2 ) {
                    //cout << "DEBUG: neightbor " << label_2 << " found" << endl;
                    neighbor_existed = true;
                    // update the neighbor
                    (*it2).weight = weight;
                    break;
                }
            }
            if (!neighbor_existed) {
                // add one neighbor
                Neighbor n (label_2, weight);
                (*it).neighbors.push_back(n);
                //cout << "DEBUG: neightbor " << label_2 << " added" << endl;

                // update degree
                (*it).v_degree++;
            }

            break;
        }
    }
    if (!vertex_existed) {
        Vertex v1 (label_1);

        // add one neighbor
        Neighbor n (label_2, weight);
        v1.neighbors.push_back(n);

        this->VertexArr.push_back(v1);
        //cout << "DEBUG: vertex " << label_1 << " added" << endl;
    }

    // add one vertex of lable == label_2 if it does not existe
    vertex_existed = false;
    neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_2 ) {
            //cout << "DEBUG: vertex " << label_2 << " found" << endl;
            vertex_existed = true;

            // update or add its neighbor
            for (list<Neighbor>::iterator it2=(*it).neighbors.begin(); it2 != (*it).neighbors.end(); ++it2) {
                if ( (*it2).label == label_1 ) {
                    //cout << "DEBUG: neightbor " << label_1 << " found" << endl;
                    neighbor_existed = true;
                    // update the neighbor
                    (*it2).weight = weight;
                    break;
                }
            }
            if (!neighbor_existed) {
                // add one neighbor
                Neighbor n (label_1, weight);
                (*it).neighbors.push_back(n);
                //cout << "DEBUG: neightbor " << label_1 << " added" << endl;

                // update degree
                (*it).v_degree++;
            }

            break;
        }
    }
    if (!vertex_existed) {
        Vertex v2 (label_2);

        // add one neighbor
        Neighbor n (label_1, weight);
        v2.neighbors.push_back(n);

        this->VertexArr.push_back(v2);
        //cout << "DEBUG: vertex " << label_2 << " added" << endl;
    }
}

void Implement::deleteEdge(const int label_1, const int label_2) {
    // search for vertex of lable == label_1
    bool vertex_existed = false;
    bool neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_1 ) {
            //cout << "DEBUG: vertex " << label_1 << " found" << endl;
            vertex_existed = true;

            // remove its neighbor
            for (list<Neighbor>::iterator it2=(*it).neighbors.begin(); it2 != (*it).neighbors.end(); ++it2) {
                if ( (*it2).label == label_2 ) {
                    //cout << "DEBUG: neightbor " << label_2 << " found" << endl;
                    neighbor_existed = true;

                    // remove the neighbor
                    (*it).neighbors.erase(it2);
                    
                    // update degree
                    (*it).v_degree--;

                    break;
                }
            }
            if (!neighbor_existed) {
                // do nothing
            }

            break;
        }
    }
    if (!vertex_existed) {
        // do nothing
    }

    // search for vertex of lable == label_2
    vertex_existed = false;
    neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label_2 ) {
            //cout << "DEBUG: vertex " << label_2 << " found" << endl;
            vertex_existed = true;

            // update or add its neighbor
            for (list<Neighbor>::iterator it2=(*it).neighbors.begin(); it2 != (*it).neighbors.end(); ++it2) {
                if ( (*it2).label == label_1 ) {
                    //cout << "DEBUG: neightbor " << label_1 << " found" << endl;
                    neighbor_existed = true;

                    // remove the neighbor
                    (*it).neighbors.erase(it2);

                    // update degree
                    (*it).v_degree--;

                    break;
                }
            }
            if (!neighbor_existed) {
                // do nothing
            }

            break;
        }
    }
    if (!vertex_existed) {
        // do nothing
    }
}

void Implement::deleteVertex(const int label) {
    // search for vertex of lable == label
    bool vertex_existed = false;
    bool neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label ) {
            //cout << "DEBUG: vertex " << label << " found" << endl;
            vertex_existed = true;

            // remove the vertex
            this->VertexArr.erase(it);

            break;
        }
    }
    if (!vertex_existed) {
        // do nothing
    }

    // search for neightbor of lable == label
    vertex_existed = false;
    neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
            // update or add its neighbor
            for (list<Neighbor>::iterator it2=(*it).neighbors.begin(); it2 != (*it).neighbors.end(); ++it2) {
                if ( (*it2).label == label ) {
                    //cout << "DEBUG: neightbor " << label << " found" << endl;
                    neighbor_existed = true;

                    // remove the neighbor
                    (*it).neighbors.erase(it2);

                    // update degree
                    (*it).v_degree--;

                    break;
                }
            }
            if (!neighbor_existed) {
                // do nothing
            }
    }
}

int Implement::degree(const int label) {
    int degree = 0;

    // search for vertex of lable == label
    bool vertex_existed = false;
    bool neighbor_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        if ( (*it).label == label ) {
            //cout << "DEBUG: vertex " << label << " found" << endl;
            vertex_existed = true;

            // return the degree
            degree = (*it).v_degree;

            break;
        }
    }
    if (!vertex_existed) {
        degree = 0;
    }

    return degree;
}

bool Implement::isExistPath(const int label_1, const int label_2) {
    // Mark all the vertices as not visited
    int n = this->VertexArr.size();
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) visited[i] = false;
    
    // Create a queue for BFS
    list<Vertex> queue;

    // Mark the current node as visited and enqueue it
    int index = -1;
    bool vertex_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        index++;
        if ( (*it).label == label_1 ) {
            //cout << "DEBUG: vertex " << label_1 << " found" << endl;
            vertex_existed = true;

            visited[index] = true;
            queue.push_back(*it);

            break;
        }
    }
    if (vertex_existed) {

        while(!queue.empty()) {
            Vertex v = queue.front();
            queue.pop_front();
            //cout << "DEBUG: BFS output " << v.label << endl;

            if (v.label == label_2) return true;
    
            for (list<Neighbor>::iterator it=v.neighbors.begin(); it != v.neighbors.end(); ++it) {
                index = -1;
                for (list<Vertex>::iterator it2=this->VertexArr.begin(); it2 != this->VertexArr.end(); ++it2) {
                    index++;
                    if ( (*it2).label == (*it).label ) {
                        //cout << "DEBUG: vertex found" << endl;

                        if(!visited[index]){
                            queue.push_back(*it2);
                            visited[index] = true;
                        }

                        break;
                    }
                }
            }
        }
    
    }

    return false;
}

void Implement::deleteGraph() {
    this->VertexArr.clear();
}

int Implement::number_of_component() {
    int number = 0;

    // Mark all the vertices as not visited
    int n = this->VertexArr.size();
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) visited[i] = false;
    
    // Create a queue for BFS
    list<Vertex> queue;

    while (true) {

        // Mark the current node as visited and enqueue it
        int index = -1;
        bool vertex_existed = false;
        for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
            index++;
            if (visited[index] == false) {
                //cout << "DEBUG: vertex found" << endl;
                vertex_existed = true;
    
                visited[index] = true;
                queue.push_back(*it);
    
                break;
            }
        }
        if (vertex_existed) {
            number++;
    
            while(!queue.empty()) {
                Vertex v = queue.front();
                queue.pop_front();
                //cout << "DEBUG: BFS output " << v.label << endl;
        
                for (list<Neighbor>::iterator it=v.neighbors.begin(); it != v.neighbors.end(); ++it) {
                    index = -1;
                    for (list<Vertex>::iterator it2=this->VertexArr.begin(); it2 != this->VertexArr.end(); ++it2) {
                        index++;
                        if ( (*it2).label == (*it).label ) {
                            //cout << "DEBUG: vertex found" << endl;
    
                            if(!visited[index]){
                                queue.push_back(*it2);
                                visited[index] = true;
                            }
    
                            break;
                        }
                    }
                }
            }
        
        }
        else {
            break;
        }
    }

    return number;
}

bool Implement::isExistCycle() {
    // Mark all the vertices as not visited and not part of recursion
    // stack
    int V = this->VertexArr.size();
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;
 
    return false;
}

Vertex& Implement::getVertexByIndex(int i) {
    int index = -1;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        index++;
        if (index == i) return *it;
    }
}

int Implement::indexOf(int label) {
    int index = -1;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        index++;
        if ((*it).label == label) return index;
    }
}

bool Implement::isCyclicUtil(int v, bool visited[], int parent) {
    // Mark the current node as visited
    visited[v] = true;
 
    Vertex vertex = this->getVertexByIndex(v);

    // Recur for all the vertices adjacent to this vertex
    for (list<Neighbor>::iterator it=vertex.neighbors.begin(); it != vertex.neighbors.end(); ++it)
    {
        int i = this->indexOf((*it).label);

        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[i])
        {
           if (isCyclicUtil(i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (i != parent)
           return true;
    }
    return false;
}

void Implement::DFS(int label) {
    // Mark all the vertices as not visited
    int n = this->VertexArr.size();
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) visited[i] = false;
    
    // Create a stack for DFS
    list<Vertex> stack;

    // Mark the current node as visited and enqueue it
    int index = -1;
    bool vertex_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        index++;
        if ( (*it).label == label ) {
            //cout << "DEBUG: vertex " << label << " found" << endl;
            vertex_existed = true;

            stack.push_back(*it);

            break;
        }
    }
    if (vertex_existed) {

        while(!stack.empty()) {
            Vertex v = stack.back();
            stack.pop_back();

            index = -1;
            for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
                index++;
                if ( (*it).label == v.label ) {
                    //cout << "DEBUG: vertex found" << endl;

                    if(!visited[index]){
                        cout << "DEBUG: DFS output " << v.label << endl;
                        visited[index] = true;

                        for(list<Neighbor>::iterator it2=v.neighbors.begin(); it2 != v.neighbors.end(); ++it2) {
                            index = -1;
                            for (list<Vertex>::iterator it3=this->VertexArr.begin(); it3 != this->VertexArr.end(); ++it3) {
                                index++;
                                if ((*it3).label == (*it2).label) {
                                    //cout << "DEBUG: vertex found" << endl;

                                    if (!visited[index]) {
                                        stack.push_back(*it3);
                                    }

                                    break;
                                }

                            }
                        }
                    }

                    break;
                }
            }
          
        }

    }

}

void Implement::BFS(int label) {
    // Mark all the vertices as not visited
    int n = this->VertexArr.size();
    bool *visited = new bool[n];
    for(int i=0; i<n; i++) visited[i] = false;
    
    // Create a queue for BFS
    list<Vertex> queue;

    // Mark the current node as visited and enqueue it
    int index = -1;
    bool vertex_existed = false;
    for (list<Vertex>::iterator it=this->VertexArr.begin(); it != this->VertexArr.end(); ++it) {
        index++;
        if ( (*it).label == label ) {
            //cout << "DEBUG: vertex " << label << " found" << endl;
            vertex_existed = true;

            visited[index] = true;
            queue.push_back(*it);

            break;
        }
    }
    if (vertex_existed) {

        while(!queue.empty()) {
            Vertex v = queue.front();
            queue.pop_front();
            cout << "DEBUG: BFS output " << v.label << endl;
    
            for (list<Neighbor>::iterator it=v.neighbors.begin(); it != v.neighbors.end(); ++it) {
                index = -1;
                for (list<Vertex>::iterator it2=this->VertexArr.begin(); it2 != this->VertexArr.end(); ++it2) {
                    index++;
                    if ( (*it2).label == (*it).label ) {
                        //cout << "DEBUG: vertex found" << endl;

                        if(!visited[index]){
                            queue.push_back(*it2);
                            visited[index] = true;
                        }

                        break;
                    }
                }
            }
        }
    
    }
}


