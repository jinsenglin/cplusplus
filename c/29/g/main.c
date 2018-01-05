#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100000] = { 0 };
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        printf("DEBUG: %d\n", a[i]);
    }
}
