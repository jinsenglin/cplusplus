#include <stdio.h>
#include <stdbool.h>

int last_bit(int *num) {
    int one_or_zero = *num - (*num >> 1)*2;
    *num = *num >> 1;

    return one_or_zero;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[100000] = { 0 };
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        while (a[i] > 0) {
            printf("DEBUG: %d\n", last_bit(&a[i]));
        }
    }
}
