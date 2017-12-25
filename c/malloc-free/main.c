#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char c;
    struct _Node* next;
} Node;

void fn() {
}

int main() {
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

    printf("going to free(head)\n");
    free(head);
    head = NULL;

    printf("note: can not double-free, which means free(cursor) is not allowed after free(head). so just make it NULL\n");
    cursor = NULL;
}
