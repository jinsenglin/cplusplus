#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node *next;
} Node;

void Create_List(Node** head, char data) {
    if (*head == NULL) {
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

void delete_node() {
}

void insert_node() {
}

void print_list() {
}

int main() {
    Node *head = NULL;
    char data = 'c';
    Create_List(&head, data);
}
