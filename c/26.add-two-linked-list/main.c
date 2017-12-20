#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Node *head_a = NULL, *head_b = NULL;
    int data;

    // DEBUG
    /*
    Node n;
    n.data = 100;
    head_a = &n;
    Node** pptr = &head_a;
    printf("%d\n", n.data);
    printf("%d\n", (*head_a).data);
    printf("%d\n", (*(*pptr)).data);
    if ( (*(*pptr)) == NULL ) printf("NULL\n"); // error: invalid operands to binary expression
    return 0;
    */
    // end of DEBUG

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
          //printf("DEBUG: main.c :: %d\n", (*head_a).data);
        } else break;
    }
    while(1) { // read List b
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_b, data);
        } else break;
    }
    
    Node *head = Add_List( head_a, head_b );
    
    Print_List( head_a );
    Print_List( head_b );
    Print_List( head );
    
    Free_List( head_a );
    Free_List( head_b );
    Free_List( head );
    
    return 0;
}


