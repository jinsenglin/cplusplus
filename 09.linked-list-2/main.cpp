#include <iostream>

using namespace std; 

/*
Define a linked list class

instead of defining a single linked list class, here we define three classes

class Node for item of linked list
class Chain for linked list itself
class Implement, a subclass of class Chain
*/

//The data structure that present a node.
class Node
{
friend class Chain;
public:
    //the pointer to next node in the chain
    Node *next;

    //stores the data
    int data;

    //constructor and destructor
    Node(){
        this->next = NULL;
    }
    Node(const int e, Node* next=NULL){
        this->data = e;
        this->next = next;
    }
    ~Node(){
        this->next = NULL;
    }
};



//It contains the fucntions that you have to override.
class Chain
{
public:
    //----------------------------------------------------------------------
    // Insert a data at the end of the linked list.
    // e.g. original list (head) : "A -> B" => InsertBack(head, C) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual void InsertBack(int data)=0;
    
    //----------------------------------------------------------------------
    // Insert a data at the front of the linked list.
    // e.g. original list (head) : "A -> B" => InsertBack(head, C) => "C -> A -> B"
    //----------------------------------------------------------------------
    virtual void InsertFront(int data)=0;

    //----------------------------------------------------------------------
    // Insert data2 after data1 in the linked list.
    // If the InsertAfter error happened , do nothing.
    // e.g. original list (head) : "A -> A" => InsertAfter(head, A, B) => "A -> B -> A"
    // e.g. original list (head) : "A -> A" => InsertAfter(head, C, B) => "A -> A"
    //----------------------------------------------------------------------
    virtual void InsertAfter(int data1, int data2)=0;

    //----------------------------------------------------------------------
    // Remove the data from the linked list.
    // If the Delete error happened , do nothing.
    // e.g. original list (head) : "A -> B -> C" => Delete(head,B) => "A -> C"
    // e.g. original list (head) : "A -> B -> C" => Delete(head,Y) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual void Delete(int data)=0;
    
    //----------------------------------------------------------------------
    // Remove the data from the front of the linked list.
    // If the Delete error happened , do nothing.
    // e.g. original list (head) : "A -> B -> C" => DeleteFront(head) => "B -> C"
    //----------------------------------------------------------------------
    virtual void DeleteFront()=0;

    //----------------------------------------------------------------------
    // Remove the data from the end of the linked list.
    // If the Delete error happened , do nothing.
    // e.g. original list (head) : "A -> B -> C" => DeleteBack(head) => "A -> B"
    //----------------------------------------------------------------------
    virtual void DeleteBack()=0;
    
    //----------------------------------------------------------------------
    // Reverse the linked list.
    // e.g. original list (head) : "A -> B -> C" =>Reverse(head) => "C -> B -> A"
    //----------------------------------------------------------------------
    virtual void Reverse()=0;

    string toString(){
        Node* tmp = this->head;
        string result = "";
        if(tmp == NULL){
            result.append("Empty");
        }
        while(tmp != NULL) {
            string num = std::to_string(tmp->data);
            result.append(num);
            if(tmp->next != NULL)
                result.append("->");
            tmp = tmp->next;
        }
    return result;
}

    Node* head = NULL;
};



class Implement: public Chain
{
public:
    Implement& operator+(Implement right);
    void InsertBack(int data);
    void InsertFront(int data);
    void InsertAfter(int data1, int data2);
    void Delete(int data);
    void DeleteFront();
    void DeleteBack();
    void Reverse();
    
};



// Implement virtual methods of class Chain

Implement& Implement::operator+(Implement right) {
    cout << "DEBUG: +" << endl;
    cout << "DEBUG: this->head->data = " << this->head->data << endl;
    cout << "DEBUG: right.head->data = " << right.head->data << endl;

    Node *current1 = this->head;
    Node *current2 = right.head;

    while (current1 != 0 || current2 != 0) {
        if (current1 != 0 && current2 != 0) {
            cout << "DEBUG: current1->data + current2->data" << endl;

            current1->data += current2->data;

            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1 != 0 && current2 == 0) {
            cout << "DEBUG: do nothing" << endl;
            break;
        }
        else if (current1 == 0 && current2 != 0) {
            cout << "DEBUG: current1 = current2" << endl;
            current1 = current2; // TODO need modify this chain
            break;
        }
    }

    return *this;
}



void Implement::InsertBack(int data) {
    Node *n = head;
    while (n !=0) {
        if (n->data == data) return;
        n = n->next;
    }

    Node *newNode = new Node(data);
    if (head == 0) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != 0) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = NULL;
};



void Implement::InsertFront(int data) {
    Node *n = head;
    while (n !=0) {
        if (n->data == data) return;
        n = n->next;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
};



void Implement::InsertAfter(int data1, int data2) {
    Node *n = head;
    while (n !=0) {
        if (n->data == data2) return;
        n = n->next;
    }

    Node *current = head;
    Node *newNode = new Node(data2);
    while ((current != NULL) && (data1 != current->data))
    {
        current = current->next;
    }
    if(current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    }
};



void Implement::Delete(int data) {
    Node *current = head;
    Node *prev = head;
    Node *newNode = new Node(data);
    while ((current != NULL) && (data != current->data))
    {
        prev = current;
        current = current->next;
    }
    if(current != NULL) {
        prev->next = current->next;
        delete current;
        current = NULL;
    }
};



void Implement::DeleteFront() {
    Node *current = head;
    if(current != NULL)
    {
        head = head->next;
        delete current;
        current = NULL;
    }
};



void Implement::DeleteBack() {
    Node *current = head;
    Node *prev = head;
    if(current != NULL)
    {
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
        current = NULL;
    }
};



void Implement::Reverse() {
    Node *prev = 0;
    Node *current = head;
    while (current) {
        Node *r = prev;
        prev = current;
        current = current->next;
        prev->next = r;
    }
    head = prev;
};



/*
Input

3
InsertBack 1
InsertAfter 1 2
Reverse 
2
InsertBack 2
InsertBack 4
ADD
1
Reverse

Output

1->2->4->5
*/

void load_data() {
    // declare three linked list objects
    Implement list1;
    Implement list2;
    Implement list3;

    // load M
    string M;
    getline(cin, M);
    cout << "DEBUG: M = " << M << endl;

    // load M instructions
    for (int i=0; i<atoi(M.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO: use the first linked list object
        list1.InsertBack(i+1);
    }

    // load N
    string N;
    getline(cin, N);
    cout << "DEBUG: N = " << N << endl;

    // load N instructions
    for (int i=0; i<atoi(N.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO: use the second linked list object
        list2.InsertBack(i+1);
    }

    // load ADD
    string ADD;
    getline(cin, ADD);
    cout << "DEBUG: ADD = " << ADD << endl;

    // use the first and second linked list objects to make the third linked list object
    list3 = list1 + list2;

    // load K
    string K;
    getline(cin, K);
    cout << "DEBUG: K = " << K << endl;

    // load K instructions
    for (int i=0; i<atoi(K.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO: use the third linked list object
    }

    // print the third linked list object
    cout << list3.toString() << endl;
}

int main() {
    load_data(); 
    return 0; 
}
