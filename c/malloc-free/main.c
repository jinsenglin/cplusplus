#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char c;
    struct _Node* next;
} Node;

void fn(Node** list) {
    printf("START fn\n");
    printf("&list = %p\n", &list);
    printf("list = %p\n", list);
    printf("*list = %p\n", *list);

    Node* head = malloc(sizeof(Node));
    head->c = 'c';
    head->next = head;
    printf("&head = %p\n", &head);
    printf("head = %p\n", head);
    printf("(*head).c = %c\n", (*head).c);
    printf("head->c = %c\n", head->c);
    printf("head->next = %p\n", head->next);
    printf("head->next->c = %c\n", head->next->c);

    Node* cursor = head;
    printf("&cursor = %p\n", &cursor);
    printf("cursor = %p\n", cursor);
    printf("(*cursor).c = %c\n", (*cursor).c);
    printf("cursor->c = %c\n", cursor->c);
    printf("cursor->next = %p\n", cursor->next);
    printf("cursor->next->c = %c\n", cursor->next->c);

    *list = head;
    printf("END fn\n\n");
}

typedef struct _BiNode {
    char data;
    struct _BiNode* prev;
    struct _BiNode* next;
} BiNode;

typedef struct _BiNodeList {
    BiNode* head;
    BiNode* cursor;
    BiNode* tail;
} BiNodeList;

void init_list(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    l = malloc(sizeof(BiNodeList));
    l->head = NULL;
    l->cursor = NULL;
    l->tail = NULL;

    // update list
    *list = l;
}

void dump_list(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    BiNode* n = l->head;
    while ( n != NULL ) {
        printf("%c", n->data);
        n = n->next;
    }
    printf("\n");
}

BiNode* new_node(char data) {
    BiNode* n = malloc(sizeof(BiNode));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void add_node(BiNodeList** list, char data) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        printf("DEBUG: add_node :: empty list\n");

        // new node
        BiNode* n = new_node(data);

        // update alias
        l->head = n;
        l->cursor = n->next;
        l->tail = n;

        // update list
        *list = l;
    }
    else {
        printf("DEBUG: add_node :: non-empty list\n");

        if ( l->cursor == NULL ) {
            printf("DEBUG: add_node :: cursor position is NULL i.e. after tail\n");

            // new node
            BiNode* n = new_node(data);
            n->prev = l->tail;

            // update prev node
            l->tail->next = n;

            // update alias
            l->cursor = n->next;
            l->tail = n;
        }
        else {
            printf("DEBUG: add_node :: cursor position is not NULL\n");

            // new node
            BiNode* n = new_node(data);

            // update prev node if exists TODO
            // update current node TODO
            // update alias TODO
            // update list TODO
        }
    }
}

void backward(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        printf("DEBUG: backward :: empty list\n");
    }
    else {
        printf("DEBUG: backward :: non-empty list\n");

        if ( l->cursor == NULL ) {
            printf("DEBUG: backward :: cursor position is NULL i.e. after tail\n");

            l->cursor = l->tail;
        }
        else {
            printf("DEBUG: backward :: cursor position is not NULL\n");

            if ( l->cursor == l->head ) {
                printf("DEBUG: backward :: cursor position is at head\n");
            }
            else {
                printf("DEBUG: backward :: cursor position is not at head\n");

                l->cursor = l->cursor->prev;
            }
        }
    }

    printf("DEBUG: backward :: l->cursor = %p\n", l->cursor);
}

void forward(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        printf("DEBUG: forward :: empty list\n");
    }
    else {
        printf("DEBUG: forward :: non-empty list\n");

        if ( l->cursor == NULL ) {
            printf("DEBUG: forward :: cursor position is NULL i.e. after tail\n");
        }
        else {
            printf("DEBUG: forward :: cursor position is not NULL\n");

            l->cursor = l->cursor->next;
        }
    }

    printf("DEBUG: forward :: l->cursor = %p\n", l->cursor);
}

void del_node(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        printf("DEBUG: del_node :: empty list\n");
    }
    else {
        printf("DEBUG: del_node :: non-empty list\n");

        // TODO
    }
}

int main() {
    // Case 2
    BiNodeList* list = NULL;
    init_list(&list);
    add_node(&list, 'a');
    add_node(&list, 'b');
    add_node(&list, 'c');
    backward(&list);
    backward(&list);
    forward(&list);
    forward(&list);
    dump_list(&list);

    // Case 1
/*
    Node* head = NULL;
    fn(&head);

    printf("&head = %p\n", &head);
    printf("head = %p\n", head);
    printf("(*head).c = %c\n", (*head).c);
    printf("head->c = %c\n", head->c);
    printf("head->next = %p\n", head->next);
    printf("head->next->c = %c\n", head->next->c);

    Node* cursor = head;
    printf("&cursor = %p\n", &cursor);
    printf("cursor = %p\n", cursor);
    printf("(*cursor).c = %c\n", (*cursor).c);
    printf("cursor->c = %c\n", cursor->c);
    printf("cursor->next = %p\n", cursor->next);
    printf("cursor->next->c = %c\n", cursor->next->c);

    printf("\ngoing to free(head)\n");
    free(head);
    head = NULL;

    printf("note: can not double-free, which means free(cursor) is not allowed after free(head). so just make it NULL\n");
    cursor = NULL;
*/
}
