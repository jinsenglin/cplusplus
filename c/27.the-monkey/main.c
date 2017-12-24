#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node *prev;
    struct _Node *next;
} Node;

void insert_node(Node** head, Node** cursor, char data) {
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

void delete_node(Node** head, Node** cursor) {
}

void go_backward(Node** cursor) {
}

void go_forward(Node** cursor) {
}

void print_list(Node** head) {
    Node *current = *head;

    while (current != NULL) {
        printf("%c", (*current).data);
        current = (*current).next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    Node *cursor = NULL;
    char data;
    //Create_List(&head, data);


    // read one character at one time
    while ((data = getchar()) != '\n') {
        if (data == 'D') {
            // The capital letter ‘D’ represents that Evan deletes a character. If there is no character after the cursor, it does nothing.
            delete_node(&head, &cursor);
        }
        else if (data == '<') {
            // Character ‘<’ represents that Evan left shifts the cursor. If the cursor is located at the front of the sentence, it does nothing.
            go_backward(&cursor);
        }
        else if (data == '>') {
            // Character ‘>’ represents that Evan right shifts the cursor. If the cursor is located at the back of the sentence, it does nothing.
            go_forward(&cursor);
        }
        else {
            // The lowercase letter from ‘a’ to ‘z’ represents that Evan types a lowercase character (same as your record).
            // The underline symbol ‘_' represents that Evan types ‘_’.
            insert_node(&head, &cursor, data);
        }
    }

    // print the result
    print_list(&head);
}
