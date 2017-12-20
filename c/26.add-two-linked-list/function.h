#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void Create_List(Node**, int);
Node* Add_List(Node*, Node*);
void Print_List(Node*);
void Free_List(Node*);

void Create_List(Node** head, int data) {}

Node* Add_List(Node* head1, Node* head2) {
    return NULL;
}

void Print_List(Node* head) {}

void Free_List(Node* head){}
