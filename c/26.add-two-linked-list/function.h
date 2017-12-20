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

void Create_List(Node** head, int data) {
    if (*head == NULL) {
        /* wrong
        Node n;
        n.data = data;
        *head = &n;
        */

        // correct
        *head = malloc(sizeof(Node));
        (*(*head)).data = data;
    }
    else {
        //printf("DEBUG: function.h :: %d\n", (*(*head)).data);
        Node *prev;
        Node *current = *head;

        while (current != NULL) {
            prev = current;
            //printf("DEBUG: function.h :: %d\n", (*current).data);
            current = (*current).next;
        }
       
        (*prev).next = malloc(sizeof(Node));
        (*((*prev).next)).data = data; 
    }
}

Node* Add_List(Node* head1, Node* head2) {
    return NULL;
}

void Print_List(Node* head) {
}

void Free_List(Node* head){
}
