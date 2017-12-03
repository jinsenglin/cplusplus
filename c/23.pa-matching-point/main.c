#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//char s[] = "htisanaughtyboy";
//char t[] = "ht";

char* s = "htisanaughtyboy";
char* t = "ht";

void fn(int t_size) {
    for (int i=t_size-1; i>0; i--) {
        printf("DEBUG: ");
        for (int j=i; j<t_size; j++) {
            printf("%c", t[j]);
        }
        printf("\n");
    }
}

int indexOf(int s_start, int t_size) {
    for (int i=s_start; i<strlen(s)-t_size+1; i++) {
        bool found = true;
        for (int j=0; j<t_size; j++) {
            if (t[j] != s[i+j]) {found = false; break;}
        }
        if (found) return i;
    }

    // return -1 if not found  
    return -1;
}

int main() {
    printf("DEBUG: %d\n", indexOf(0, strlen(t)));
    fn(strlen(t));
}
