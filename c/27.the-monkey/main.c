#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node *prev;
    struct _Node *next;
} Node;

void insert_node(Node** head, Node** cursor, char data) {
    if (*head == NULL) {
        // new node and update head
        *head = malloc(sizeof(Node));
        (*(*head)).data = data;

        // update cursor
        *cursor = *head;
    }
    else {
        if (*cursor == NULL) {
            // new node and update cursor
            *cursor = malloc(sizeof(Node));
            (*(*cursor)).data = data;
            (*(*cursor)).next = *head;

            // update head
            (*(*head)).prev = *cursor;
            *head = *cursor;
        }
        else {
            // new node and update cursor
            Node* next = (*(*cursor)).next;
            (*(*cursor)).next = malloc(sizeof(Node));
            (*(*(*cursor)).next).next = next;
            (*(*(*cursor)).next).data = data;
            (*(*(*cursor)).next).prev = *cursor;
            *cursor = (*(*cursor)).next;
        }
    }
}

void delete_node(Node** head, Node** cursor) {
    if (*head == NULL) {
        // do nothing
    }
    else {
        if (*cursor == NULL) {
            if ((*(*head)).next == NULL) {
                free(*head);
                *head = NULL;
                // TODO free memory
            }
            else {
                *head = (*(*head)).next;
                free((*(*head)).prev);
                (*(*head)).prev = NULL;
                // TODO free memory
            }
        }
        else {
            if ((*(*cursor)).next == NULL) {
                // do nothing
            }
            else {
                if ((*(*(*cursor)).next).next == NULL) {
                    free((*(*cursor)).next);
                    (*(*cursor)).next = NULL;
                    // TODO free memory
                }
                else {
                    (*(*(*(*cursor)).next).next).prev = *cursor;
                    Node* tmp = (*(*cursor)).next;
                    (*(*cursor)).next = (*(*(*cursor)).next).next;
                    free(tmp);
                    // TODO free memory
                }
            }
        }
    }
}

void go_backward(Node** head, Node** cursor) {
    if (*head == NULL) {
        // do nothing
    }
    else {
        if (*cursor == NULL) {
            // do nothing
        }
        else {
            if ((*(*cursor)).prev == NULL) {
                *cursor = NULL;
            }
            else {
                // update cursor
                *cursor = (*(*cursor)).prev;
            }
        }
    }
}

void go_forward(Node** head, Node** cursor) {
    if (*head == NULL) {
        // do nothing
    }
    else {
        if (*cursor == NULL) {
            *cursor = *head;
        }
        else {
            if ((*(*cursor)).next == NULL) {
                // do nothing
            }
            else {
                // update cursor
                *cursor = (*(*cursor)).next;
            }
        }
    }
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

    // read one character at one time
    while ((data = getchar()) != '\n') {
        if (data == 'D') {
            // The capital letter ‘D’ represents that Evan deletes a character. If there is no character after the cursor, it does nothing.
            delete_node(&head, &cursor);
        }
        else if (data == '<') {
            // Character ‘<’ represents that Evan left shifts the cursor. If the cursor is located at the front of the sentence, it does nothing.
            go_backward(&head, &cursor);
        }
        else if (data == '>') {
            // Character ‘>’ represents that Evan right shifts the cursor. If the cursor is located at the back of the sentence, it does nothing.
            go_forward(&head, &cursor);
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
