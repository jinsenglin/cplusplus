#include <stdio.h>
#include <stdlib.h>

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
        //printf("DEBUG: add_node :: empty list\n");

        // new node
        BiNode* n = new_node(data);

        // update alias
        l->head = n;
        l->tail = n;
        l->cursor = n->next;

        // update list
        *list = l;
    }
    else {
        //printf("DEBUG: add_node :: non-empty list\n");

        if ( l->cursor == NULL ) {
            //printf("DEBUG: add_node :: cursor position is NULL i.e. after tail\n");

            // new node
            BiNode* n = new_node(data);
            n->prev = l->tail;

            // update prev node
            l->tail->next = n;

            // update alias
            l->tail = n;
            l->cursor = n->next;
        }
        else {
            //printf("DEBUG: add_node :: cursor position is not NULL\n");

            // new node
            BiNode* n = new_node(data);
            n->prev = l->cursor->prev;
            n->next = l->cursor;

            // update prev node if exists
            if ( l->cursor->prev != NULL ) l->cursor->prev->next = n;

            // update current node
            l->cursor->prev = n;

            // update alias
            if ( l->cursor == l->head ) l->head = n;
            l->cursor = n->next;
        }
    }
}

void backward(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        //printf("DEBUG: backward :: empty list\n");
    }
    else {
        //printf("DEBUG: backward :: non-empty list\n");

        if ( l->cursor == NULL ) {
            //printf("DEBUG: backward :: cursor position is NULL i.e. after tail\n");

            l->cursor = l->tail;
        }
        else {
            //printf("DEBUG: backward :: cursor position is not NULL\n");

            if ( l->cursor == l->head ) {
                //printf("DEBUG: backward :: cursor position is at head\n");
            }
            else {
                //printf("DEBUG: backward :: cursor position is not at head\n");

                l->cursor = l->cursor->prev;
            }
        }
    }

    //printf("DEBUG: backward :: l->cursor = %p\n", l->cursor);
}

void forward(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        //printf("DEBUG: forward :: empty list\n");
    }
    else {
        //printf("DEBUG: forward :: non-empty list\n");

        if ( l->cursor == NULL ) {
            //printf("DEBUG: forward :: cursor position is NULL i.e. after tail\n");
        }
        else {
            //printf("DEBUG: forward :: cursor position is not NULL\n");

            l->cursor = l->cursor->next;
        }
    }

    //printf("DEBUG: forward :: l->cursor = %p\n", l->cursor);
}

void del_node(BiNodeList** list) {
    // create a local alias
    BiNodeList* l = *list;

    if ( l->head == NULL ) {
        //printf("DEBUG: del_node :: empty list\n");
    }
    else {
        //printf("DEBUG: del_node :: non-empty list\n");

        if ( l->cursor == NULL ) {
            //printf("DEBUG: del_node :: cursor position is NULL i.e. after tail\n");
        }
        else {
            //printf("DEBUG: del_node :: cursor position is not NULL\n");

            // update prev node if exists
            if ( l->cursor->prev != NULL ) l->cursor->prev->next = l->cursor->next;

            // update next node if exists
            if ( l->cursor->next != NULL ) l->cursor->next->prev = l->cursor->prev;

            // update alias
            if ( l->cursor == l->head ) l->head = l->cursor->next;
            if ( l->cursor == l->tail ) l->tail = l->cursor->prev;

            BiNode* to_be_freed = l->cursor;
            l->cursor = l->cursor->next;
            free(to_be_freed);
            to_be_freed = NULL;
        }
    }
}

int main() {
    BiNodeList* list = NULL;
    init_list(&list);
    char data;

    // read one character at one time
    while ((data = getchar()) != '\n') {
        if (data == 'D') {
            // The capital letter ‘D’ represents that Evan deletes a character. If there is no character after the cursor, it does nothing.
            del_node(&list);
        }
        else if (data == '<') {
            // Character ‘<’ represents that Evan left shifts the cursor. If the cursor is located at the front of the sentence, it does nothing.
            backward(&list);
        }
        else if (data == '>') {
            // Character ‘>’ represents that Evan right shifts the cursor. If the cursor is located at the back of the sentence, it does nothing.
            forward(&list);
        }
        else {
            // The lowercase letter from ‘a’ to ‘z’ represents that Evan types a lowercase character (same as your record).
            // The underline symbol ‘_' represents that Evan types ‘_’.
            add_node(&list, data);
        }
    }

    // print the result
    dump_list(&list);

    // free memory
    free(list);
    list = NULL;
}
